#include <Platform/Platform.h>

namespace DXRPG::Engine::Renderer
{
			OpenGLShader::OpenGLShader()
			{
				this->id = glCreateProgram();
				this->isBinded = false;
			}

			OpenGLShader::~OpenGLShader()
			{
				
				glUseProgram(0);
				glDeleteProgram(this->Get_Id());

				this->uniformLocations.clear();
				this->id = 0;
			}

			void OpenGLShader::Compile(const std::string & fragFile,
				const std::string & vertFile, const std::string & geofile)
			{
				FileSystem fs;

				Compile_VertexShader(fs.ReadText(vertFile));
				Compile_FragmentShader(fs.ReadText(fragFile));
			}

			const unsigned int OpenGLShader::Get_Id() const
			{
				return this->id;
			}

			void OpenGLShader::__Compile(const std::string & source, const unsigned int & shader)
			{
				const char* shaderCode = source.c_str();
				glShaderSource(shader, 1, &shaderCode, NULL);
				glCompileShader(shader);
				glAttachShader(this->Get_Id(), shader);

				if (this->Get_Status(shader, GL_COMPILE_STATUS))
				{
					this->Link();
					if (!this->Get_Status(this->Get_Id(), GL_LINK_STATUS))
						glDeleteProgram(this->Get_Id());
				}

				glDeleteShader(shader);
			}

			void OpenGLShader::Compile_FragmentShader(const std::string & source)
			{
				if (source.size() == 0)
					return;

				this->__Compile(source, glCreateShader(GL_FRAGMENT_SHADER));
			}

			void OpenGLShader::Compile_VertexShader(const std::string & source)
			{
				if (source.size() == 0)
					return;

				this->__Compile(source, glCreateShader(GL_VERTEX_SHADER));
			}

			void OpenGLShader::Compile_GeometryShader(const std::string & source)
			{
				if (source.size() == 0)
					return;

				this->__Compile(source, glCreateShader(GL_GEOMETRY_SHADER));
			}

			void OpenGLShader::Link()
			{
				glLinkProgram(this->Get_Id());
			}

			bool OpenGLShader::Get_Status(const unsigned int & shader, const unsigned short & type)
			{
				int success = 1;
				char infolog[512];
				memset(&infolog, 0, sizeof(infolog));

				if (type == GL_COMPILE_STATUS)
					glGetShaderiv(shader, type, &success);
				else
					if (type == GL_LINK_STATUS)
						glGetProgramiv(shader, type, &success);

				if (!success)
				{
					if (type == GL_COMPILE_STATUS)
					{
						glGetShaderInfoLog(shader, sizeof(infolog), nullptr, infolog);
						if (strlen(infolog) != 0)
							OutErrorMsg("Failed to Compile Shader!");
					}
					else
					{
						if (type == GL_LINK_STATUS)
						{
							glGetProgramInfoLog(shader, sizeof(infolog), nullptr, infolog);
							if (strlen(infolog) != 0)
								OutErrorMsg("Failed to link Shader!");
						}
					}

					return false;
				}
				else
					return true;
			}

			void OpenGLShader::setBool(const std::string & name, bool value)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform1i(this->uniformLocations[name], value);
			}

			void OpenGLShader::setInt(const std::string & name, int value)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform1i(this->uniformLocations[name], value);
			}

			void OpenGLShader::setFloat(const std::string & name, float value)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform1f(this->uniformLocations[name], value);
			}

			void OpenGLShader::setVec2(const std::string & name, const glm::vec2 & value)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform2fv(this->uniformLocations[name], 1, &value[0]);
			}

			void OpenGLShader::setVec2(const std::string & name, float x, float y)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform2f(this->uniformLocations[name], x, y);
			}

			void OpenGLShader::setVec3(const std::string & name, const glm::vec3 & value)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform3fv(this->uniformLocations[name], 1, &value[0]);
			}

			void OpenGLShader::setVec3(const std::string & name, float x, float y, float z)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform3f(this->uniformLocations[name], x, y, z);
			}

			void OpenGLShader::setVec4(const std::string & name, const glm::vec4 & value)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform4fv(this->uniformLocations[name], 1, &value[0]);
			}

			void OpenGLShader::setVec4(const std::string & name, float x, float y, float z, float w)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniform4f(this->uniformLocations[name], x, y, z,w);
			}

			void OpenGLShader::setMat2(const std::string & name, const glm::mat2 & mat)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniformMatrix2fv(this->uniformLocations[name], 1, GL_FALSE, value_ptr(mat));
			}

			void OpenGLShader::setMat3(const std::string & name, const glm::mat3 & mat)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniformMatrix3fv(this->uniformLocations[name], 1, GL_FALSE, value_ptr(mat));
			}

			void OpenGLShader::setMat4(const std::string & name, const glm::mat4 & mat)
			{
				if (this->uniformLocations.find(name) == this->uniformLocations.end())
					this->uniformLocations[name] = glGetUniformLocation(this->Get_Id(), name.c_str());

				glUniformMatrix4fv(this->uniformLocations[name], 1, GL_FALSE, value_ptr(mat));
			}

			void OpenGLShader::Bind()
			{
				if (!this->isBinded)
				{
					glUseProgram(this->Get_Id());
					this->isBinded = true;
				}
			}

			void OpenGLShader::Unbind()
			{
				if (this->isBinded)
				{
					glUseProgram(0);
					this->isBinded = false;
				}
			}
}

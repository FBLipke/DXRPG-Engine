#pragma once
#include <Platform/Platform.h>
namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLShader :
				public Shader
			{
			public:
				OpenGLShader();
				virtual ~OpenGLShader();

				virtual void Bind();
				virtual void Unbind();
				virtual void Compile(const std::string & fragFile, const std::string & vertFile,
					const std::string & geofile);
				const unsigned int Get_Id() const;


			private:
				std::unordered_map<std::string, unsigned int> uniformlocations;
				bool isBinded = false;
				void __Compile(const std::string & source, const unsigned int & shader);
				void Compile_FragmentShader(const std::string & source);
				void Compile_VertexShader(const std::string & source);
				void Compile_GeometryShader(const std::string & source);
				void Link();
				bool Get_Status(const unsigned int & shader, const unsigned short & type);
				unsigned int id;

				// Geerbt über Shader
				virtual void setBool(const std::string & name, bool value) override;
				virtual void setInt(const std::string & name, int value) override;
				virtual void setFloat(const std::string & name, float value) override;
				virtual void setVec2(const std::string & name, const glm::vec2 & value) override;
				virtual void setVec2(const std::string & name, float x, float y) override;
				virtual void setVec3(const std::string & name, const glm::vec3 & value) override;
				virtual void setVec3(const std::string & name, float x, float y, float z) override;
				virtual void setVec4(const std::string & name, const glm::vec4 & value) override;
				virtual void setVec4(const std::string & name, float x, float y, float z, float w) override;
				virtual void setMat2(const std::string & name, const glm::mat2 & mat) override;
				virtual void setMat3(const std::string & name, const glm::mat3 & mat) override;
				virtual void setMat4(const std::string & name, const glm::mat4 & mat) override;
			};
		}
	}
}

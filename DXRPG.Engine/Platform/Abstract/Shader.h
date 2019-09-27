#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT Shader
			{
			public:
				Shader() {};
				virtual ~Shader() {};

				virtual void Compile(const std::string & fragFile, const std::string & vertFile, const std::string & geofile) = 0;
				virtual void Bind() = 0;
				virtual void Unbind() = 0;

				virtual void setBool(const std::string & name, bool value) = 0;

				virtual void setInt(const std::string & name, int value) = 0;

				virtual void setFloat(const std::string & name, float value) = 0;

				virtual void setVec2(const std::string & name, const glm::vec2 & value) = 0;

				virtual void setVec2(const std::string & name, float x, float y) = 0;

				virtual void setVec3(const std::string & name, const glm::vec3 & value) = 0;

				virtual void setVec3(const std::string & name, float x, float y, float z) = 0;

				virtual void setVec4(const std::string & name, const glm::vec4 & value) = 0;

				virtual void setVec4(const std::string & name, float x, float y, float z, float w) = 0;

				virtual void setMat2(const std::string & name, const glm::mat2 & mat) = 0;

				virtual void setMat3(const std::string & name, const glm::mat3 & mat) = 0;

				virtual void setMat4(const std::string & name, const glm::mat4 & mat) = 0;
			private:
			};
		}
	}
}

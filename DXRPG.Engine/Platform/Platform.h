#pragma once
#define WIN32_LEAN_AND_MEAN
#define __DLLEXPORT __declspec(dllexport)

#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>

#include <direct.h>
#include <Vendor/glm/glm.hpp>
#include <Vendor/glm/gtc/matrix_transform.hpp>
#include <Vendor/glm/gtc/type_ptr.hpp>

#include "FileSystem.h"

#include "Window/WindowState.h"
#include "Input.h"
#include "Window/Window.h"

#include "Abstract/Shader.h"
#include "Abstract/Texture.h"
#include "Abstract/Renderer.h"
#include "Abstract/VertexArrayLayout.h"
#include "Abstract/VertexBuffer.h"
#include "Abstract/IndexBuffer.h"
#include "Abstract/VertexArray.h"
#include "Abstract/Camera.h"
#include "Manager.h"

#include "OpenGL/OpenGLShader.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLRenderer.h"
#include "OpenGL/OpenGLIndexBuffer.h"
#include "OpenGL/OpenGLVertexBuffer.h"
#include "OpenGL/OpenGLVertexArray.h"
#include "DirectX/DirectXRenderer.h"
#include "OrthographicCamera.h"
#include <Platform/Common/World/Map/Layer/Tile.h>
#include <Platform/Common/World/Map/Layer/Layer.h>
#include <Platform/Common/World/Map/Map.h>
#include "Common/World/World.h"

#include "../Common.h"

namespace DXRPG
{
	namespace Engine
	{
		__DLLEXPORT bool OutErrorMsg(const char * message);

		namespace Renderer
		{
		}
	}
}


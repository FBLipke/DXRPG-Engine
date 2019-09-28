#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		class __DLLEXPORT FileSystem
		{
		public:
			FileSystem();
			virtual ~FileSystem();


			static std::string ReadText(const std::string& path);
		private:
			static std::string Get_WorkingDirectory();
			static std::string __pathSeperatorChar();
			static bool __has_endingslash(const std::string& p);
			static std::string Combine(const std::string& p1, const std::string& p2);



		};
	}
}

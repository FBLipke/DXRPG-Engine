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

			

			const std::string ReadText(const std::string & path);
		private:
			std::string Get_WorkingDirectory();
			std::string __pathSeperatorChar();
			bool __has_endingslash(const std::string& p);
			std::string Combine(const std::string& p1, const std::string& p2);



		};
	}
}

#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		FileSystem::FileSystem()
		{
		}

		FileSystem::~FileSystem()
		{
		}

		std::string FileSystem::Get_WorkingDirectory()
		{
			char cCurrentPath[255];
			memset(cCurrentPath, 0, sizeof cCurrentPath);

			_getcwd(cCurrentPath, sizeof cCurrentPath);

			std::string _path = std::string(cCurrentPath);
			return _path;
		}

		std::string FileSystem::__pathSeperatorChar()
		{
			std::string slash = "/";
#ifdef _WIN32
			slash = "\\";
#endif // _WIN32
			return slash;
		}

		bool FileSystem::__has_endingslash(const std::string& p)
		{
			return p.find_last_of(__pathSeperatorChar(), p.size()) == p.size();
		}

		std::string FileSystem::Combine(const std::string& p1, const std::string& p2)
		{
			std::string _path = p1;

			if (p1.size() == 0)
				return p2;

			if (!__has_endingslash(_path))
				_path = _path + __pathSeperatorChar();

			if (p2.size() != 0)
				return _path + p2;
			else
				return _path;
		}

		const std::string FileSystem::ReadText(const std::string & path)
		{
			std::ifstream file;
			std::string _wd = Get_WorkingDirectory();
			file.open(Combine(_wd, path).c_str());

			if (!file.bad())
			{
				std::stringstream buffer;
				buffer << file.rdbuf();
				file.close();

				return buffer.str();
			}
			return "";
		}
	}
}

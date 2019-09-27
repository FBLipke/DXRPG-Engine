#pragma once
#include <Platform\Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		class Window
		{
		public:
			Window() {};
			Window(HINSTANCE hInstance, const std::string& title);
			~Window();
			bool Inititalize();
			void Shutdown();
			LRESULT MsgProc(HWND& hwnd, UINT& msg, WPARAM& wParam, LPARAM& lParam);

			float Get_FrameBufferWidth() const;
			float Get_FrameBufferHeight() const;

			WindowState GetWindowState() const;
			void SetWindowState(const WindowState& state);
			HWND GetHWND() const;
		private:
			void __GetWindowSize();
			HINSTANCE hInstance;
			DWORD windowStyle;
			WindowState Windowstate;
			HWND hwnd;
			WNDCLASSEX wcEx;
			RECT r;
			LONG width;
			LONG height;

			LONG fbWidth;
			LONG fbHeight;



			std::string title;
		};
	}
}

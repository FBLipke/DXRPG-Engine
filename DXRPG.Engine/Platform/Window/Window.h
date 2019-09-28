#pragma once
#include <Platform\Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		class __DLLEXPORT Window
		{
		public:
			Window();
			Window(HINSTANCE hInstance, const std::string& title);
			~Window();
			bool Inititalize();
			void Shutdown() const;
			LRESULT MsgProc(HWND& hwnd, UINT& msg, WPARAM& wParam, LPARAM& lParam);

			auto Get_FrameBufferWidth() const -> float;
			auto Get_FrameBufferHeight() const -> float;

			enum WindowState GetWindowState() const;
			void SetWindowState(const WindowState& state);
			HWND GetHwnd() const;
		private:
			void __GetWindowSize();
			void __GetKeyboardInput(int key);
			HINSTANCE hInstance;
			DWORD windowStyle;
			WindowState windowState;
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

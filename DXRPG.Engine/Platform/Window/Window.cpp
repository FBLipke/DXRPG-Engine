#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace
		{
			Engine::Window* _instance = nullptr;
		}

		void Window::__GetWindowSize()
		{
			if (this == nullptr)
				return;

			RECT wRect = { 0 };
			if (GetWindowRect(hwnd, &wRect))
			{
				if (AdjustWindowRect(&wRect, this->windowStyle, FALSE))
				{
					fbWidth = wRect.right - wRect.left;
					fbHeight = wRect.bottom - wRect.top;
				}
			}
		}

		void Window::__GetKeyboardInput(int key)
		{
			if (this == nullptr)
				return;

			RECT wRect = { 0 };
		}

		LRESULT Window::MsgProc(HWND& hwnd, UINT& msg, WPARAM& wParam, LPARAM& lParam)
		{
			Common* cm = reinterpret_cast<Common*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			switch (msg)
			{
			case WM_SIZING:
				__GetWindowSize();
				cm->Get_Window()->SetWindowState(ResizeEnd);
				cm->Event();
				return 1;
			case WM_ENTERSIZEMOVE:
				cm->Get_Window()->SetWindowState(ResizeBegin);
				cm->Event();
				return 1;
			case WM_EXITSIZEMOVE:
				__GetWindowSize();
				cm->Get_Window()->SetWindowState(ResizeEnd);
				cm->Event();
				return 1;
			case WM_KEYDOWN:
				if (cm == nullptr)
					return 1;
				cm->Get_Input()->Set_PressedKey(wParam);
				cm->Get_Window()->SetWindowState(KeyPressed);
				cm->Event();
				return 1;
			case WM_KEYUP:
				if (cm == nullptr)
					return 1;

				cm->Get_Input()->Set_ReleasedKey(wParam);
				cm->Get_Window()->SetWindowState(keyReleased);
				cm->Event();
				return 1;
			case WM_SIZE:
				switch (wParam)
				{
				case SIZE_MAXIMIZED:
					__GetWindowSize();
					cm->Get_Window()->SetWindowState(Maximized);
					return 1;
				case SIZE_MINIMIZED:
					__GetWindowSize();
					cm->Get_Window()->SetWindowState(Minimized);
					return 1;
				case SIZE_RESTORED:
					__GetWindowSize();
					cm->Get_Window()->SetWindowState(Restored);
					return 1;
				default:
					__GetWindowSize();
					cm->Get_Window()->SetWindowState(ResizeEnd);

					return 1;
				}
				cm->Event();
				return 1;
			case WM_DESTROY:
				PostQuitMessage(0);
				cm->Get_Window()->SetWindowState(NoState);
				return 1;

			default:
				return DefWindowProc(hwnd, msg, wParam, lParam);
			}
		}

		HWND Window::GetHWND() const
		{
			return hwnd;
		}

		WindowState Window::GetWindowState() const
		{
			return this->Windowstate;
		}

		void Window::SetWindowState(const WindowState& state)
		{
			if (this == nullptr)
				return;

			this->Windowstate = state;
		}

		float Window::Get_FrameBufferWidth() const
		{
			return static_cast<float>(this->fbWidth);
		}

		float Window::Get_FrameBufferHeight() const
		{
			return static_cast<float>(this->fbHeight);
		}

		LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			return _instance->MsgProc(hwnd, msg, wParam, lParam);
		}

		Window::Window(HINSTANCE hInstance, const std::string& title)
		{
			this->hInstance = hInstance;
			this->title = title;
			this->hwnd = nullptr;
			this->Windowstate = NoState;
			this->width = 1280;
			this->height = 800;
			this->r = { 0, 0, width, height };
			this->windowStyle = WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
		}

		Window::~Window()
		{
		}

		bool Window::Inititalize()
		{
			ZeroMemory(&wcEx, sizeof(WNDCLASSEX));
			wcEx.cbClsExtra = sizeof(Common);
			wcEx.cbWndExtra = sizeof(Common);
			wcEx.cbSize = sizeof(WNDCLASSEX);
			wcEx.style = CS_HREDRAW | CS_VREDRAW;
			wcEx.hInstance = this->hInstance;
			wcEx.lpfnWndProc = MainWndProc;

			wcEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wcEx.hCursor = LoadCursor(NULL, IDC_ARROW);
			wcEx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
			wcEx.lpszClassName = "COMMONCLASS";
			wcEx.lpszMenuName = "IDR_MENU1";
			wcEx.hIconSm = wcEx.hIcon;

			if (!RegisterClassEx(&wcEx))
				return OutErrorMsg("Failed to register Window Class");

			if (AdjustWindowRect(&r, this->windowStyle, FALSE))
			{
				fbWidth = r.right - r.left;
				fbHeight = r.bottom - r.top;

				int x = GetSystemMetrics(SM_CXSCREEN / 2 - fbWidth / 2);
				int y = GetSystemMetrics(SM_CYSCREEN / 2 - fbHeight / 2);

				hwnd = CreateWindow(wcEx.lpszClassName, this->title.c_str(), this->windowStyle,
					x, y, fbWidth, fbHeight, NULL, NULL, hInstance, NULL);

				if (!hwnd) return OutErrorMsg("Failed to create Window");

				//

				return true;
			}
			
			return false;
		}

		void Window::Shutdown()
		{
			DestroyWindow(GetHWND());
			UnregisterClass(wcEx.lpszClassName, hInstance);
		}
	}

}

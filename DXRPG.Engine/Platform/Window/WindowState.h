#pragma once
typedef enum __DLLEXPORT WindowState
{
	Maximized = 0,
	Minimized,
	Restored,
	NoState,
	PaintBegin,
	PaintEnded,
	ResizeBegin,
	KeyPressed,
	keyReleased,
	Resizing,
	ResizeEnd
} WindowState;
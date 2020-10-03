#pragma once

namespace leo {
	class MouseEventListener {
	public:
		enum  MouseButton_enum
		{
			MOUSE_BUTTON_LEFT, 
			MOUSE_BUTTON_RIGHT, 
			MOUSE_BUTTON_MIDDLE, 
		};

		virtual void onMouseDown(int mx, int my, MouseButton_enum button, double t_ms) = 0;
		
		virtual void onMouseUp(int mx, int my, MouseButton_enum button, double t_ms) = 0;

		virtual void onMouseDragged(int mx, int my, double t_ms) = 0;


	};
}
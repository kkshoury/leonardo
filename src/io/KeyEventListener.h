#pragma once

namespace leo {
	class KeyEventListener {
	public:
		const static char LEO_KEY_SPACE = 0;
		const static char LEO_KEY_CTRL = 1;
		const static char LEO_KEY_M = 'M';

		virtual void onKeyDown(char key, double t_ms) = 0;
		virtual void onKeyUp(char key, double t_ms) = 0;
		virtual void onClick(char key, double t_ms) = 0;
		virtual void onDoubleClick(char key, double t_ms) = 0;


	};
}
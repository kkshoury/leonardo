#pragma once

namespace leo {

	class Color {
		int val;
		char r();
		char g();
		char b();
		char a();

		void r(char r);
		void g(char g);
		void b(char b);
		void a(char a);

		int getInt();
		void setInt(int color);

		float getFloat();
		void setFloat(float col);

		Color(char r, char g, char b, char a);
		Color(int rgba);
	};
}
#pragma once

namespace leo {
	
	class IScene {

	};


	class ISceneObject {

	};

	class Scene : IScene {
	public:

		virtual void clear() = 0;
		virtual void dispose() = 0;
		virtual int getBackgroundColor() const = 0;
		virtual void setBackgroundColor(int color) = 0;

		virtual void add(const ISceneObject& object) = 0;

	private:
		int _bgColor;


	};



}
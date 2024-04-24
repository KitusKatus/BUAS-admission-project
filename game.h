#pragma once

namespace Tmpl8 {

class Surface;
class Game
{
public:
	Game()
	{
		mouseDown = 0;
		mouseUp = 0;
		mousex = 0;
		mousey = 0;
		keyDown = 0;
		screen = nullptr;
	}
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp(int button) { mouseUp = button; }
	void MouseDown(int button) { mouseDown = button; }
	void MouseMove( int x, int y ) { mousex = x, mousey = y; }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown(int key) { keyDown = key; }
private:
	Surface* screen;
	int mousex, mousey;
	int mouseDown;
	int mouseUp;
	int keyDown;
	//int buttonPress;
};

}; // namespace Tmpl8
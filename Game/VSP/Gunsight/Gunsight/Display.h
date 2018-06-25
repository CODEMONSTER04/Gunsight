#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL.h>
#include <glew.h>
#include <string>
class Display
{
public:
	Display();
	virtual ~Display();
	void Quit();
	void Start();
	void Update();
	void RenderNew();
private:
	SDL_Window * p_wnd;
	SDL_GLContext p_ctxt;
};
#endif


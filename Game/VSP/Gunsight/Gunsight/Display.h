#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL.h>
#include <glew.h>
#include <string>
#include <vector>
#include "Mesh.h"
class Display
{
public:
	Display();
	virtual ~Display();
	void Quit();
	void Start();
	void Update();
	void RenderNew();
	std::vector<Mesh> meshes;
private:
	SDL_Window * p_wnd;
	SDL_GLContext p_ctxt;
};
#endif


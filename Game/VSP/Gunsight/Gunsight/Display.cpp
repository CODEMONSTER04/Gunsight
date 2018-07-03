#include "stdafx.h"
#include "Display.h"


Display::Display()
{
	p_wnd = SDL_CreateWindow("Gunsight", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN);
	p_ctxt = SDL_GL_CreateContext(p_wnd);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 64);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	Start();
	Update();
}


Display::~Display()
{
	Quit();
}

void Display::Quit()
{
	SDL_GL_DeleteContext(p_ctxt);
	SDL_DestroyWindow(p_wnd);
	SDL_Quit();
}
void Display::Start()
{

}
void Display::RenderNew()
{
	for (size_t i = 0; i < meshes.size(); i++)
	{
		meshes[i]->Draw();
	}
}
void Display::Update()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	while (true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		RenderNew();
		SDL_GL_SwapWindow(p_wnd);
		
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				Quit();
			}
		}
	}
}
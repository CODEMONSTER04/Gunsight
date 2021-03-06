// Gunsight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Display.h"
#include <iostream>
#include "Mesh.h"
#include "Material.h"
#undef main
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	glewInit();
	Display* d = new Display();
	std::vector<Texture> t;
	Shader defs("Data/Shaders/Default");
	Mesh* mesh = Mesh::LoadMesh("Data/Meshes/TestMesh");
	Material m(defs, t);
	mesh->material = m;
	d->meshes.push_back(mesh);
    return 0;
}
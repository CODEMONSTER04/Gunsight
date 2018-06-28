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
	std::vector<Texture> t;
	Shader defs("Shaders/Default");
	Material m(defs, t);
	Mesh* mesh = Mesh::LoadMesh("Meshes/TestMesh");
	Texture diffuse;
	diffuse.type = "diffuse";
	diffuse.path = "Textures/TestDiffuse.t.gsa";
	Display* d = new Display();
    return 0;
}
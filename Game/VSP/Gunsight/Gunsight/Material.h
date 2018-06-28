#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H
#include "Shader.h"
#include <vector>
struct Texture
{
	unsigned int id;
	std::string type;
	std::string path;
};


class Material
{
public:
	Material(Shader shader, std::vector<Texture> textures);
	Material();
	virtual ~Material();
	void Use();
private:
	Shader p_shader;
	std::vector<Texture> p_textures;
};
#endif


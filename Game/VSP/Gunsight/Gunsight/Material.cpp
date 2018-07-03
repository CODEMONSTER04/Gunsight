#include "stdafx.h"
#include "Material.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Material::Material(Shader shader, std::vector<Texture> textures)
{
	p_shader = shader;
	p_textures = textures;
}
Material::Material()
{

}
Material::~Material()
{
}
void Material::Use()
{
	p_shader.Bind();
}
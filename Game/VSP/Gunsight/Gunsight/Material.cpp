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
	unsigned int diffuse_nr = 1;
	unsigned int specular_nr = 1;
	unsigned int metallic_nr = 1;
	unsigned int normal_nr = 1;
	unsigned int opacity_nr = 1;
	unsigned int height_nr = 1;
	unsigned int emission_nr = 1;
	unsigned int ao_nr = 1;
	for (size_t i = 0; i < p_textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		std::string num;
		std::string type = p_textures[i].type;
		if (type == "diffuse")
		{
			num = std::to_string(diffuse_nr++);
		}
		else if (type == "specular")
		{
			num = std::to_string(specular_nr++);
		}
		else if (type == "metallic")
		{
			num = std::to_string(metallic_nr++);
		}
		else if (type == "normal")
		{
			num = std::to_string(normal_nr++);
		}
		else if (type == "opacity")
		{
			num = std::to_string(opacity_nr++);
		}
		else if (type == "height")
		{
			num = std::to_string(height_nr++);
		}
		else if (type == "emission")
		{
			num = std::to_string(emission_nr++);
		}
		else if (type == "ambientocclusion")
		{
			num = std::to_string(ao_nr++);
		}
		p_shader.SetFloat((type + num).c_str(), i);
		glBindTexture(GL_TEXTURE_2D, p_textures[i].id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		int w, h, c;
		unsigned char* d = stbi_load(p_textures[i].path.c_str(), &w, &h, &c, 0);
		if (d)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, d);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cerr << "Failed To Load Texture" << std::endl;
		}
	}
	glActiveTexture(GL_TEXTURE0);
}
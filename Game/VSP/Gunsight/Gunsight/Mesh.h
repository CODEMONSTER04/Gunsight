#pragma once
#ifndef MESH_H
#define MESH_H
#include <glm.hpp>
#include <vector>
#include <string>
#include "Material.h"
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normals;
	glm::vec2 texturecoordinates;
};
class Mesh
{
public:
	Mesh(Material m);
	Mesh();
	virtual ~Mesh();
	bool Visible;
	std::vector<Vertex> verts;
	static Mesh* LoadMesh(const std::string& fileName);
	void Draw();
	Material material;
private:
	GLuint VBO, VAO;
};
#endif


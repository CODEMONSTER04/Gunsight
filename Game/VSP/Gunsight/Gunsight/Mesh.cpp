#include "stdafx.h"
#include "Mesh.h"


Mesh::Mesh(Material m)
{
	material = m;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
}


Mesh::~Mesh()
{
	
}
Mesh::Mesh()
{

}
Mesh* Mesh::LoadMesh(const std::string& fileName)
{
	Mesh* m = new Mesh();
	std::ifstream file;
	file.open((fileName + ".m.gsa").c_str());
	int i = 0;
	std::string line;
	std::vector<Vertex> verts;
	Vertex current;
	char* end;
	glm::vec3 cp;
	glm::vec3 cn;
	glm::vec2 ct;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			if (i == 0)
			{
				float x = std::strtof(line.c_str(), &end);
				cp.x = x;
				continue;
			}
			else if (i == 1)
			{
				float y = std::strtof(line.c_str(), &end);
				cp.y = y;
				continue;
			}
			else if (i == 2)
			{
				float z = std::strtof(line.c_str(), &end);
				cp.z = z;
				current.position = cp;
				continue;
			}
			else if (i == 3)
			{
				float x = std::strtof(line.c_str(), &end);
				cn.x = x;
				continue;
			}
			else if (i == 4)
			{
				float y = std::strtof(line.c_str(), &end);
				cn.y = y;
				continue;
			}
			else if (i == 5)
			{
				float z = std::strtof(line.c_str(), &end);
				cn.z = z;
				current.normals = cn;
				continue;
			}
			else if (i == 6)
			{
				float x = std::strtof(line.c_str(), &end);
				ct.x = x;
				continue;
			}
			else if (i == 7)
			{
				float y = std::strtof(line.c_str(), &end);
				ct.y = y;
				current.texturecoordinates = ct;
				i = 0;
				verts.push_back(current);
				continue;
			}
			i++;
		}
	}
	else
	{
		std::cerr << "Unable To Load Mesh: " << fileName << std::endl;
	}
	m->verts = verts;
	return m;
}
void Mesh::Draw()
{
	material.Use();
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, verts.size(), &verts.data()[0], GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, verts.size(), GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, verts.size(), GL_FLOAT, GL_FALSE, 0, (void*)offsetof(Vertex, normals));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, verts.size(), GL_FLOAT, GL_FALSE, 0, (void*)offsetof(Vertex, texturecoordinates));

	glDrawArrays(GL_TRIANGLES, 0, verts.size());
	glBindVertexArray(0);

}
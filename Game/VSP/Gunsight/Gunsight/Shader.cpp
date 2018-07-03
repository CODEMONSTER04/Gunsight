#include "stdafx.h"
#include "Shader.h"

Shader::Shader(const std::string& fileName)
{
	p_program = glCreateProgram();
	p_shaders[0] = CreateShader(LoadShader(fileName + ".v.gsa"), GL_VERTEX_SHADER);
	p_shaders[1] = CreateShader(LoadShader(fileName + ".f.gsa"), GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUMBER_OF_SHADERS; i++)
	{
		glAttachShader(p_shaders[i], p_program);
	}
	glLinkProgram(p_program);
	CheckShaderError(p_program, GL_LINK_STATUS, true, "Program Linking Failed: ");
	glValidateProgram(p_program);
	CheckShaderError(p_program, GL_VALIDATE_STATUS, true, "Program Invalid: ");

}
void Shader::BindAttribute(GLuint index, const GLchar* name)
{
	glBindAttribLocation(p_program, index, name);
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUMBER_OF_SHADERS; i++)
	{
		glDetachShader(p_shaders[i], p_program);
		glDeleteShader(p_shaders[i]);
	}
	glDeleteProgram(p_program);
}
std::string Shader::LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable To Load Shader: " << fileName << std::endl;
	}

	return output;
}
void Shader::Bind()
{
	glUseProgram(p_program);
}
Shader::Shader()
{

}
void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}
GLuint Shader::CreateShader(const std::string& data, GLenum shaderType)
{
	GLuint shad = glCreateShader(shaderType);
	if (shad == 0)
	{
		std::cerr << "Can't Create Shader!!" << std::endl;
	}
	const GLchar* sourcestrs[1];
	GLint sourcestrlen[1];
	sourcestrs[0] = data.c_str();
	sourcestrlen[0] = data.length();

	glShaderSource(shad, 1, sourcestrs, sourcestrlen);
	glCompileShader(shad);
	CheckShaderError(shad, GL_COMPILE_STATUS, false, "Failed To Compile Shader: ");
	return shad;
}
void Shader::SetFloat(const std::string& name, float value)
{
	glUniform1i(glGetUniformLocation(p_program, name.c_str()), value);
}
void Shader::SetInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(p_program, name.c_str()), value);
}
void Shader::SetBool(const std::string& name, bool value)
{
	glUniform1i(glGetUniformLocation(p_program, name.c_str()), value);
}
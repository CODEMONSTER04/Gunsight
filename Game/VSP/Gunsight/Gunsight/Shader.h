#pragma once
#ifndef SHADER_H
#define SHADER_H
#include <glew.h>
#include <SDL.h>
#include <string>
#include <fstream>
#include <iostream>
class Shader
{
public:
	Shader(const std::string& fileName);
	Shader();
	virtual ~Shader();
	void Bind();
	void SetFloat(const std::string& name, float value);
	void SetInt(const std::string& name, int value);
	void SetBool(const std::string& name, bool value);
	void BindAttribute(GLuint index, const GLchar* name);
private:
	GLuint p_program;
	static const unsigned int NUMBER_OF_SHADERS = 2;
	GLuint p_shaders[NUMBER_OF_SHADERS];
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	static std::string LoadShader(const std::string& fileName);
	static GLuint CreateShader(const std::string& data, GLenum shaderType);
};
#endif
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <stb_image.h>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <array>

const int Width = 800;
const int Height = 600;

int main() {
	assert(glfwInit());

	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Hello Triangle", nullptr, nullptr);
	assert(Window);

	glfwMakeContextCurrent(Window);
	glewExperimental = GL_TRUE;
	assert(glewInit() == GLEW_OK);


	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;
	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);
	std::cout << "OpenGl Version: " << GLMajorVersion << "." << GLMinorVersion << std::endl;
	std::cout << "OpenGl Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "OpenGl Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	// Definir triangulo (vertices)
	std::array<glm::vec3, 3> Vertices = {
		glm::vec3(-0.5f, -0.5f, 0.0f),
		glm::vec3(0.5f, -0.5f, 0.0f),
		glm::vec3(0.0f, 0.5f, 0.0f)
	};

	// Criar buffer
	GLuint VertexBuffer;

	// Cria o buffer
	glGenBuffers(1, &VertexBuffer);

	// Bind para o buffer
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

	// Copia para a GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices.data(), GL_STATIC_DRAW);

	// Definir cor de fundo
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(Window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();

		glfwSwapBuffers(Window);
	}
	
	glfwTerminate();

	return 0;
}
#include <vector>
#include "renderer.h"
#include "shaders.h"


Renderer::Renderer() {
	_verts = std::vector<float>({ 0.5f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f });
	_cols = std::vector<float>({
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0
		});

}

Renderer::~Renderer() {

}

void Renderer::initBuffers() {
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int cap = 10000;
	glGenBuffers(1, &vertexPosBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexPosBuffer);
	glBufferData(GL_ARRAY_BUFFER, _verts.size() * sizeof(float), &_verts.front(), GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &vertexColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, _cols.size() * sizeof(float), &_cols.front(), GL_DYNAMIC_DRAW);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	buffersInitialized = true;


}

void Renderer::initShaders() {
	int vs = leo::Shaders::createAndCompileShader(GL_VERTEX_SHADER, leo::Shaders::getDefaultVertexShader());
	int fs = leo::Shaders::createAndCompileShader(GL_FRAGMENT_SHADER, leo::Shaders::getDefaultFragmentShader());

	int program = leo::Shaders::createProgram(vs, fs);
	this->program = program;
	glUseProgram(program);
	shadersInitialized = true;

}

void Renderer::init() {
	initBuffers();
	initShaders();
}

void Renderer::dispose() {

}

void Renderer::render() {
	if (!shadersInitialized) {
		this->initShaders();
	}

	if (!buffersInitialized) {
		this->initBuffers();
	}

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, _verts.size() / 3);

}

void Renderer::add() {

}

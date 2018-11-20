#include "glad/include/glad/glad.h"
 
#include <vector>

class Renderer {
public:
	Renderer();

	~Renderer();

	void initBuffers();
	void initShaders();
	void init();
	void dispose();
	void render();
	void add();

private:
	bool shadersInitialized = false;
	bool buffersInitialized = false;
	std::vector<float> _verts;
	std::vector<float> _cols;
	GLuint vertexPosBuffer;
	GLuint vertexColorBuffer;
	GLuint program = 0;
};
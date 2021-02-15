#include "Src\graphics\Window.h"
#include "Src\maths\maths.h"
#include "Src\graphics\shader.h"

#include "Src\graphics\buffers\buffer.h"
#include "Src\graphics\buffers\indexbuffer.h"
#include "Src\graphics\buffers\vertexarray.h"

#include "Src\graphics\renderable2d.h"
#include "Src\graphics\simple2drenderer.h"
#include "Src/graphics/batchrenderer2D.h"

#include"Src/graphics/static_sprite.h"
#include "Src/graphics/sprite.h"

#include<time.h>

int main() {
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Ridheesh", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Src/shaders/basic.vert", "Src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);

	srand(time(NULL));
	
	std::vector<Renderable2D*> sprites;

	for (float y = 0; y < 9.0f; y+=0.05) {
		for (float x = 0; x < 16.0f; x+=0.05) {
			sprites.push_back(new Sprite(x, y, 0.04f, 0.04f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	//StaticSprite sprite1(5.0f, 5.0f, 4.0f, 4.0f, maths::vec4(1, 0, 1, 1), shader);
	//StaticSprite sprite2(7.0f, 1.0f, 2.0f, 3.0f, maths::vec4(0, 0, 1, 1), shader);
	//Simple2DRenderer renderer;
	Sprite sprite1(5.0f, 5.0f, 4.0f, 4.0f, maths::vec4(1, 0, 1, 1));
	Sprite sprite2(7.0f, 1.0f, 2.0f, 3.0f, maths::vec4(0, 0, 1, 1));
	BatchRenderer2D renderer;



	while (!window.closed()) {

		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f),(float)(9.0f -  y * 9.0f / 540.0f)));
		renderer.begin();

		for (int i = 0; i < sprites.size(); i++) {
		renderer.submit(sprites[i]);
		}

		renderer.end();
		renderer.flush();

		window.update();
	}

	return 0;
}





//recheck the two matrix from video 5 didn't really get that 
//check the WHAT comments for wtf happened in 5.5 video
//video 6 wut openGL stuff has to be redone
// Leaving the project as ojn 27-Apr-2020 because did not know most of the information needed, welp decided to carry on becasueof the japanese guy cheering me on
// The next video is the renderer video #7 Ep. 7: Buffers and Vertex Arrays 


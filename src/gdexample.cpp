#include "gdexample.h"

using namespace godot;


void GDExample::_register_methods() {
	register_method("_ready", &GDExample::_ready);
	register_method("_process", &GDExample::_process);
	register_method("_draw", &GDExample::_draw);

}


GDExample::GDExample() {
}


GDExample::~GDExample() {

}


void GDExample::_init() {

}


void GDExample::_ready() {
	colors.append(Color(0.0, 0.0, 0.0));
	colors.append(Color(1.0, 0.0, 1.0));
	colors.append(Color(0.0, 0.0, 1.0));
	colors.append(Color(0.0, 1.0, 0.0));
	colors.append(Color(0.0, 0.5, 1.0));
	colors.append(Color(1.0, 0.0, 0.0));
	colors.append(Color(1.0, 0.5, 0.0));
	colors.append(Color(1.0, 1.0, 0.0));
	colors.append(Color(1.0, 1.0, 1.0));
}


void GDExample::_process(float delta) {
	//update();
}


void GDExample::_draw() {
	
	int64_t startmsecs = OS::get_singleton()->get_system_time_msecs();
	// from http ://www.quitebasic.com/prj/math/mandelbrot/
	Color c;
	float l = 100.0;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			float u = i / 250.0 - 1.5;
			float v = j / 250.0 - 1.0;
			float x = u;
			float y = v;
			float n = 0.0;
			float r = x * x;
			float q = y * y;
			while ((r + q) < 4.0 && n < l)
			{
				y = 2.0 * x * y + v;
				x = r - q + u;
				r = x * x;
				q = y * y;
				n = n + 1.0;
			}
			if (n < 10.0)
			{
				c = colors[0];
			}
			else
			{
				c = colors[int(round(8.0 * (n - 10.0) / (l - 10.0)))];
			}
			draw_rect(Rect2(Vector2(i + 1000, j), Vector2(1, 1)), c, true, 1.0, false);
		}
	}
	int64_t stopmsecs = OS::get_singleton()->get_system_time_msecs();
	Godot::print("gdnative C++ result milliseconds: ");
	Godot::print(String::num_int64(stopmsecs - startmsecs));
}


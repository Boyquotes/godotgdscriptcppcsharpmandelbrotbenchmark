#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <OS.hpp>
#include <string>


namespace godot {

class GDExample : public Node2D {
	GODOT_CLASS(GDExample, Node2D)

private:
	PoolColorArray colors = PoolColorArray();

public:
	static void _register_methods();

	GDExample();
	~GDExample();

	void _init();

	void _ready();
	void _process(float delta);
	void _draw();

};

}

#endif

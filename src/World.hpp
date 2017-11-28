#ifndef CWORLD_HPP
#define CWORLD_HPP

#include "Light.hpp"
#include "Ball.hpp"
#include "Table.hpp"
#include <iostream>
#include <list>
#include <vector>


class World {
public:
	Table* table;
	Shape* list[15]; //15 balls
	// std::list<Shape*> ObjectList;
	// std::vector<Shape*>* ObjectVector;

	World();
	~World();
	void draw_world(); // draw all objects in the world
	void reset();
};

#endif

/**
 * File: World.hpp
 */

#include "World.hpp"


World::World() {

}

World::~World(){

}

void World::draw_world() {


}

void World::reset(){
    list[0]->reset();
    list[1]->reset();
    list[2]->reset();
}


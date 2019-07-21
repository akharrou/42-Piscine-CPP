
#include "../Includes/ObjectField.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

SpaceObject::SpaceObject(int nx, int ny) {
	pos.x = nx ;
	pos.y = ny;
}

void	SpaceObject::update() {
	pos.y += 1;
}

vec2i	SpaceObject::getPos() const {
	return pos;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	ObjectField::setBounds(rect a) {
	field_bounds = a;
}

std::vector<SpaceObject>	ObjectField::getData() const {
	return object_set;
}

void	ObjectField::erase(size_t i) {
    object_set.erase(object_set.begin() + i);
}

void	ObjectField::update() {

    // update existing objects
    for( size_t i = 0; i < object_set.size(); i++ ) {

        if( object_set.at(i).getPos().y > field_bounds.bot() )
            object_set.erase(object_set.begin() + i);

        object_set.at(i).update();
    }

    // spawn a new object
    SpaceObject s(rand() % field_bounds.width(), 0);
    object_set.push_back(s);
}

#include "Shape.h"

void Shape::paint() { draw(); }

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}
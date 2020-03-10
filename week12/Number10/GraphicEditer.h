#pragma 
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "UI.h"

class GraphicEditer {
	Shape* pStart;
	Shape* pLast;
	int index;
	void insert(int num);
	void indexDelete(int num);
public:
	GraphicEditer() { pStart = pLast = NULL; index = 0; }
	void call();
};

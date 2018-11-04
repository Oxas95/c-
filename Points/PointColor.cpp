#include "PointColor.h"
#include <iostream>

PointColor::PointColor() : color(0){}

PointColor::PointColor(int x, int y, int _color) : Point(x,y), color(_color){}

PointColor::PointColor(PointColor& p){
	x = p.x;
	y = p.y;
	color = p.color;
}

PointColor::~PointColor(){
	cout << "PointColor deleted\n" << endl 
}

PointColor::PointColor(Point& p, int _color) : Point(p);, color(_color);{}

void PointColor::afficher(){
	Point::afficher();
	cout << ", color = " << color;
}

int PointColor::getColor(){
	return color;
}

Point& PointColor::getPoint(){
	return *this;
}

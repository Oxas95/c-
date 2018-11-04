#include "PointColor.h"
#include <iostream>

using namespace std;

PointColor::PointColor() : Point(0,0), color(0){}

PointColor::PointColor(int x, int y, int color) : Point(x,y){
	this->color = color;
}

PointColor::PointColor(PointColor& p){
	x = p.x;
	y = p.y;
	color = p.color;
}

PointColor::~PointColor(){
	cout << "PointColor deleted\n" << endl;
}

PointColor::PointColor(Point& p, int color) : Point(p){
	this->color = color;
}

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

#include <iostream>
#include "Point.h"

Point::Point(){
	this->x = 0;
	this->y = 0;
}


Point::Point(int x,int  y){
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p){
	this->x = p.x;
	this->y = p.y;
}

Point ::~Point(){
	std:: cout << "destructeur \n";
}
void Point::afficher(){
	std :: cout << "x = " << x << ",y = " << y;
}

Point Point::cloner(const Point& p){
	Point* c = new Point();
	this->x = p.x;
	this->y = p.y;
	return *c;
}

int Point::getX(){ return x; }

int Point::getY(){ return y; }

void Point::setX(int x){ this->x = x; }

void Point::setY(int y){ this->y = y; }

#include "Forme.h"

Forme::Forme() : centre(), color(0){}

Forme::Forme(Forme& f){
	centre = f.centre;
	color = f.color;
}

void Forme::deplacer(int x, int y){
	centre.setX(centre.getX() + x);
	centre.setY(centre.getY() + y);
}

#include "Segment.h"

Point& Segment::getExt1(){
	return ext1;
}

Point& Segment::getExt2(){
	return ext2;
}

Segment::Segment(){
	this->ext1 = Point();
	this->ext2 = Point();
}
 
Segment::Segment(Segment& s){
	
	this->ext1 = s.ext1;
	this->ext2 = s.ext2;
}

Segment::Segment(Point& tmp,Point& tmp2) : ext1(tmp), ext2(tmp2){}

bool Segment::estVertical(){
	return ext1.getX() == 0 && ext2.getX() == 0;
}

bool Segment::estHorizontal(){
	return ext1.getY() == 0 && ext2.getY() == 0;
}

bool Segment::estDiagonale(){
	return (!this->estVertical() && !this->estHorizontal());
}

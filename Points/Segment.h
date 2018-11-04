#ifndef Segment_h
#define Segment_h

#include "Point.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

class Segment{
	private:
		Point ext1;
		Point ext2;
	
	public:
		Point& getExt1();
		Point& getExt2();
		
		Segment();
		Segment(Segment&);
		Segment(Point& ,Point&);
		bool estVertical();
		bool estHorizontal();
		bool estDiagonale();
	
};

#endif 

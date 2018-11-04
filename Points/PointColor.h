#ifndef PointColor_h
#define PointColor_h

#include "Point.h"

class PointColor : public Point {
	
	private :
		int color;
		
	public :
		PointColor();
		PointColor(int x, int y, int color);
		PointColor(PointColor&);
		~PointColor();
		PointColor(Point&, int color);
		void afficher();
		int getColor();
		Point& getPoint();
}

#endif

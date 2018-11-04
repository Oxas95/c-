#ifndef point_h
#define point_h

class Point{
	
	protected:
	int x;
	int y;
	
	public:
		Point();
		Point(int x ,int y);
		Point(const Point&);
		~Point();
		void afficher();
		Point cloner (const Point&);
		int getX();
		int getY();
		void setX(int);
		void setY(int);
};

#endif 

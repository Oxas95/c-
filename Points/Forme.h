#ifndef Forme_h
#define Forme_h

#include "Point.h"

class Forme{
	protected :
		Point centre;
		int color;
		
	public :
		Forme();
		Forme(Forme&);
		void deplacer(int x, int y);
		virtual void afficher() = 0;
		
}

#endif

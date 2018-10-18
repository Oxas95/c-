#ifndef Vecteur_h
#define Vecteur_h
#include <iostream>

using namespace std;

typedef struct elem{
	int value;
	struct elem* suiv;
}element;

class Vecteur {
	private :
		element* head; 
		int size;
		
	public :
		Vecteur();
		~Vecteur();
		Vecteur(const Vecteur&);
		
		int getSize();
		int getValue(int pos);
		void setValue(int pos, int newValue);
		void addValueDebut(int value);
		void addValueFin(int value);
		void removeValue(int pos);
		int containValue(int valueToSearch);
		friend ostream& operator<<(ostream&, Vecteur&);
		Vecteur& operator+=(Vecteur& v);
		Vecteur& operator=(Vecteur& v);
};

#endif

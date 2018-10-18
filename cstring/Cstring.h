#ifndef Cstring_h
#define Cstring_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "string.h"

using namespace std;

class Cstring {
	private :
		char* chaine;
		int size;
		static int nbChaines;
		
	public :
		Cstring();
		Cstring(Cstring&);
		Cstring(const char);
		Cstring(const char*);
		~Cstring();
		
		static int nbrChaines();
		
		int getSize();
		char* getString();
		char charAt(int i);
		
		void setNew(const char*);
		
		Cstring& plus(const char);
		Cstring& plus(const char*);
		Cstring& plus(Cstring&);
		
		//friend 	Cstring& operator+(Cstring&, Cstring&);
				Cstring& operator=(Cstring&);
				Cstring& operator+=(Cstring&);
				Cstring& operator+=(const char*);
				Cstring& operator+=(char);
		friend	ostream& operator<<(ostream&, Cstring&);
		
		bool plusGrandQue(Cstring&);
		bool infOuEgale(Cstring&);
		
		Cstring& plusGrand(Cstring&);
};
#endif 

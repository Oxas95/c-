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
		static int nbChaines;
		
	public :
		Cstring();
		Cstring(Cstring& Cstr);
		Cstring(const char caractere);
		Cstring(const char* chaine);
		~Cstring();
		
		static int nbrChaines();
		
		int length();
		char* getString();
		char charAt(int i);
		
		void setNew(const char* str);
		
		Cstring& plus(const char caractere);
		Cstring& plus(const char* chaine);
		Cstring& plus(Cstring& chaine);
		
		friend 	Cstring& operator+(Cstring& chaine, Cstring& chaine2);
				Cstring& operator=(Cstring& chaine);
		
		int plusGrandQue(Cstring& chaine);
		int infOuEgale(Cstring& chaine);
		
		Cstring& plusGrand(Cstring& chaine);
};
#endif 

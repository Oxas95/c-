#ifndef Definition_h
#define Definition_h

#include "Cstring.h"

class Definition {
	private :
		Cstring clef;
		Cstring def;
	
	public :
		~Definition();
		Definition(const char*, const char*);
		char* getDef();
		char* getClef();
};

#endif

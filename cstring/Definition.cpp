#include "Definition.h"

Definition::~Definition(){}

Definition::Definition(const char* _clef, const char* _def) : clef(_clef), def(_def){}

char* Definition::getDef(){
	return def.getString();
}

char* Definition::getClef(){
	return clef.getString();
}

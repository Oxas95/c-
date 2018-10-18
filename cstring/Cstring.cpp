#include "Cstring.h"
using namespace std;

#define debug 0

void chaineSup(){ if(debug)cout << "Cstring object desallocated\n"; }
void chaineAdd(){ if(debug)cout << "Cstring object allocated\n"; }

#define FIN '\0'
int Cstring::nbChaines = 0;

Cstring::Cstring(){
	chaine = new char[1];
	chaine[0] = FIN;
	size = 0;
	nbChaines++;
	chaineAdd();
}

Cstring::Cstring(Cstring& Cstr){
	delete[] chaine;
	size = Cstr.size;
	chaine = new char[size + 1];
	for (int i = 0; i < size; i++){
		chaine[i] = Cstr.chaine[i];
	}
	chaine[size + 1] = FIN;
	chaineAdd();
}

Cstring::Cstring(const char caractere){
	chaine = new char[2];
	chaine[0] = caractere;
	chaine[1] = FIN;
	size = 1;
	nbChaines++;
	chaineAdd();
}

Cstring::Cstring(const char* str){
	size = strlen(str);
	chaine = new char[size + 1];
	for (int i = 0; i <= size; i++){
		chaine[i] = str[i];
	}
	nbChaines++;
	chaineAdd();
}

Cstring::~Cstring(){
	delete[] this->chaine;
	nbChaines--;
	chaineSup();
}

int Cstring::getSize(){
	return size;
}

int Cstring::nbrChaines(){
	return nbChaines;
}

char* Cstring::getString(){
	return chaine;
}

char Cstring::charAt(int i){
	if(size)
		if(i >= 0 && i <= size)
			return chaine[i];
		else return -1;
	else return -1;
}

void Cstring::setNew(const char* str){
	delete [] chaine;
	size = strlen(str);
	chaine = new char[size + 1];
	strcpy(chaine,str);
}

Cstring& Cstring::plus(const char caractere){
	++size;
	int i;
	char* string = new char[size + 1];
	for (i = 0; i < size - 1; i++){
		string[i] = chaine[i];
	}
	string[i++] = caractere;
	string[i] = FIN;
	
	delete[] this->chaine;
	this->chaine = string;
	return *this;
}

Cstring& Cstring::plus(const char* toAdd){
	int i, size2 = strlen(toAdd);
	char* str = new char[(size + size2) + 1];
	for (i = 0; i < size; i++)
		str[i] = chaine[i];
	
	for (; i < size + size2; i++)
		str[i] = toAdd[i - size];
	
	str[i] = '\0';
	
	delete[] chaine;
	chaine = str;
	size += size2;
	return *this;
}

Cstring& Cstring::plus(Cstring& toAdd){
	char* str = new char[(size + toAdd.size) + 1];
	int i;
	for (i = 0; i < size; i++)
		str[i] = chaine[i];
	
	for (; i < size + toAdd.size; i++)
		str[i] = toAdd.chaine[i - size];
	
	str[i] = '\0';
	
	delete[] chaine;
	chaine = str;
	size += toAdd.size;
	return *this;
}

/*Cstring& operator+(Cstring& left,Cstring& right){
	return left.plus(right);
}*/

Cstring& Cstring::operator=(Cstring& str){
	if(this != &str){
		delete[] chaine;
		size = str.size;
		chaine = new char[size + 1];
		for (int i = 0; i <= size; i++){
			chaine[i] = str.chaine[i];
		}
	}
	return *this;
}

Cstring& Cstring::operator+=(Cstring& str){
	this->plus(str);
	return *this;
}

Cstring& Cstring::operator+=(const char* str){
	this->plus(str);
	return *this;
}

Cstring& Cstring::operator+=(char caractere){
	this->plus(caractere);
	return *this;
}

ostream& operator<<(ostream& flux, Cstring& str){
	flux << str.getString();	
	return flux;
}

bool Cstring::plusGrandQue(Cstring& str){
	if (size > str.size) return true;
	return false;
}

bool Cstring::infOuEgale(Cstring& str){
	if (size > str.size) return false;
	return true;
}

Cstring& Cstring::plusGrand(Cstring& str){
	if (size > str.size) {
		return *this;
	}
	else return str;
}

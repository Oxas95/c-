#include "Cstring.h"

#define debug 1

void chaineSup(){ if(debug)cout << "Cstring object desallocated\n"; }
void chaineAdd(){ if(debug)cout << "Cstring object allocated\n"; }

#define FIN '\0'
char* varAff = 0;
int Cstring::nbChaines = 0;

Cstring::Cstring(){
	chaine = new char[1];
	chaine[0] = FIN;
	nbChaines++;
	chaineAdd();
}

Cstring::Cstring(Cstring& Cstr){
	delete[] chaine;
	int size = Cstr.length();
	this->chaine = new char[size + 1];
	for (int i = 0; i < size; i++){
		this->chaine[i] = Cstr.chaine[i];
	}
	chaine[size + 1] = FIN;
	chaineAdd();
}

Cstring::Cstring(const char caractere){
	chaine = new char[2];
	chaine[0] = caractere;
	chaine[1] = FIN;
	nbChaines++;
	chaineAdd();
}

Cstring::Cstring(const char* chaine){
	int length = strlen(chaine) + 1;
	this->chaine = new char[length];
	for (int i = 0; i < length; i++){
		this->chaine[i] = chaine[i];
	}
	nbChaines++;
	chaineAdd();
}

Cstring::~Cstring(){
	delete[] this->chaine;
	nbChaines--;
	if(nbChaines == 0 && varAff){
		free(varAff);
		varAff = 0;
		if(debug)cout << "cached var is free\n";
	}
	chaineSup();
}

int Cstring::length(){
	int i = 0;
	while(chaine[i++] != FIN);
	return i - 1;
}

int Cstring::nbrChaines(){
	return nbChaines;
}

char* Cstring::getString(){
	int length = this->length();
	if(varAff){
		free(varAff); varAff = 0;
	}
	varAff = (char*) malloc(length * sizeof(char) + 1);
	if(debug) cout << "cached var not free" << endl;
	for (int i = 0; i < length + 1; i++){
		varAff[i] = chaine[i];
	}
	return varAff;
}

char Cstring::charAt(int i){
	int length = this->length();
	if(length)
		if(i >= 0 && i <= length)
			return chaine[i];
		else return -1;
	else return -1;
}

void Cstring::setNew(const char* str){
	delete [] this->chaine;
	int taille = strlen(str) + 1;
	this->chaine = new char[taille];
	strcpy(this->chaine,str);
}

Cstring& Cstring::plus(const char caractere){
	int length = this->length() + 1,i;
	char* string = new char[length + 1];
	for (i = 0; i < length - 1; i++){
		string[i] = this->chaine[i];
	}
	string[i++] = caractere;
	string[i] = FIN;
	
	Cstring *s = new Cstring(string);
	delete[] string;
	return *s;
}

Cstring& Cstring::plus(const char* chaine){
	int length = this->length(),i;
	int str = strlen(chaine);
	char* string = new char[length + str + 1];
	for (i = 0; i < length; i++){
		string[i] = this->chaine[i];
	}
	for (; i < str + length; i++){
		string[i] = chaine[i - length];
	}
	string[i + length] = FIN;
	Cstring *s = new Cstring(string);
	delete[] string;
	return *s;
}

Cstring& Cstring::plus(Cstring& chaine){
	Cstring* s = new Cstring();
	char str = new char[this->length() + chaine.length() + 1];
	strcpy(str,this->getString());
	strcpy(str,chaine.getString());
	return str;
}

Cstring& operator+(Cstring& chaine,Cstring& chaine2){
	
}

Cstring& Cstring::operator=(Cstring& str){
	if(this != &str){
		delete[] this->chaine;
		int size = str.length();
		this->chaine = new char[size + 1];
		for (int i = 0; i <= size; i++){
			this->chaine[i] = str.chaine[i];
		}
	}
	return *this;
	
}
 
int Cstring::plusGrandQue(Cstring& chaine){
	if (this->length() > chaine.length()) return 1;
	return 0;
}

int Cstring::infOuEgale(Cstring& chaine){
	if (this->length() > chaine.length()) return 0;
	return 1;
}

Cstring& Cstring::plusGrand(Cstring& chaine){
	if (this->length() > chaine.length()) {
		return *this;
	}
	else return chaine;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Vecteur.h"

using namespace std;

#define debug 1

Vecteur::Vecteur(){
	head = 0;
	if(debug) cout << "Vecteur créé" << endl;
}

Vecteur::~Vecteur(){
	element* clone;
	while(head){
		clone = head->suiv;
		delete head;
		head = clone;
	}
	head = 0;
	if(debug) cout << "Vecteur détruit" << endl;
}

Vecteur::Vecteur(const Vecteur& v){
	element *cloneV = v.head;
	while(cloneV){
		this->addValueFin(cloneV->value);
		cloneV = cloneV->suiv;
	}
	if(debug) cout << "Vecteur créé" << endl;
}

int Vecteur::getSize(){
	return size;
}

int Vecteur::getValue(int pos){
	if(pos <= size && pos > 0){
		element* clone = head;
		for (int i = 1; i <= pos; i++){
			clone = clone->suiv;
		}
		return clone->value;
	}
	delete this;
	cout << "erreur : élément demandé : " << pos << ", nombre d'éléments max : " << size << endl;
	exit(1);
}

void Vecteur::setValue(int pos, int newValue){
	if(pos <= size && pos > 0){
		element* clone = head; 
		for (int i = 1; i <= pos; i++){
			clone = clone->suiv;
		}
		clone->value = newValue;
	}
	cout << "erreur : élément demandé : " << pos << ", nombre d'éléments max : " << size << endl;
}

void Vecteur::addValueDebut(int value){
	element* clone = new element();
	clone->value = value;
	clone->suiv = head;
	size++;
}

void Vecteur::addValueFin(int value){
	element* clone = head;
	while(clone){
		clone = clone->suiv;
	}
	clone = new element();
	clone->value = value;
	clone->suiv = 0;
	size++;
}

void Vecteur::removeValue(int pos){
	if(size > 0){
		element* clone = head;
		if(pos == 0){
			head = head->suiv;
			delete clone;
		}
		else if(pos == size){
			for (int i = 1; i < pos; i++){
				clone = clone->suiv;
			}
			delete clone->suiv;
			clone->suiv = 0;
		}
		else if(pos < size){
			element* suiv;
			for (int i = 1; i < pos; i++){
				clone = clone->suiv;
			}
			suiv = clone->suiv->suiv;
			delete clone->suiv;
			clone->suiv = suiv;
		}
	}
}

int Vecteur::containValue(int valueToSearch){
	element* clone = head;
	int pos = 1;
	while(clone){
		if(valueToSearch == clone->value) break;
		clone = clone->suiv;
		pos++;
	}
	if(pos > size) return 0;
	else return pos;
}

ostream& operator<<(ostream& flux, Vecteur& v){
	element *cloneV = v.head;
	while(cloneV){
		flux << (int)cloneV->value << " ";
		cloneV = cloneV->suiv;
	}
	return flux;
}

Vecteur& Vecteur::operator+=(Vecteur& v){
	element *cloneV = v.head;
	while(cloneV){
		this->addValueFin(cloneV->value);
		cloneV = cloneV->suiv;
	}
	return *this;
}

Vecteur& Vecteur::operator=(Vecteur& v){
	element* clone;
	while(head){
		clone = head->suiv;
		delete head;
		head = clone;
	}
	head = 0;
	element *cloneV = v.head;
	while(cloneV){
		this->addValueFin(cloneV->value);
		cloneV = cloneV->suiv;
	}
	return *this;
}

#include <iostream>
#include "Vecteur.h"

using namespace std;

int main(){
	Vecteur v();
	v->addValueFin(10);
	cout << v << endl;
	v->addValueDebut(100);
	cout << v << endl;
	v->addValueFin(1);
	cout << v << endl;

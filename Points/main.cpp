#include <iostream>
#include "Point.h"
#include "PointColor.h"
#include "Forme.h"
using namespace std;

int main(){
	PointColor p1;
	int i=p1.getColor();
	cout << i << endl;
	p1.afficher();
	
}

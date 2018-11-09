#include <iostream>
#include "ingresso.h"

using namespace std;

int main(){
	Ingresso i(25, 17.5);
	IngressoVIP k(2.50, 30, 10);

	cout << i;

	cout << endl;

	cout << k;

	return 0;
}
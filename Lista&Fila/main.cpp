#include "fila.h"

#include <iostream>

#include <string>

int main(int argc, char const *argv[])
{

	Fila<string> f(4);

	f.vazio();
	f.enfileira("Jerffeson");

	f.enfileira("Andre");

	f.enfileira("Fernanda");

	f.enfileira("Allan");

	f.enfileira("Silvio");

	cout << "\nLista vazia: " << f.vazio() << endl;
	cout << "Lista Cheia: " << f.cheio() << endl << endl;

	cout << f.desenfileira() << endl;

	cout << f.desenfileira() << endl;

	cout << f.desenfileira() << endl << endl;

	f.enfileira("Pedro");

	cout << f.desenfileira() << endl;

	cout << f.desenfileira() << endl;

	cout << "\vLista vazia: " << f.vazio() << endl;
	cout << "Lista Cheia: " << f.cheio() << endl;
	
	return 0;
}
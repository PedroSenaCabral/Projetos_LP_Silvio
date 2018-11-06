#include "Pilha.h"

#include <iostream>

#include <string>
#include <algorithm> // Transformar string em minuscula
#include <assert.h>  

bool verificarFrase(string& frase) {
	unsigned int aux = frase.length()/2;
	Pilha<char> pilha(aux);

	/*
	caso a frase seja ímpar, o primeiro caractere que deve ser lido é n+1,
	exemplo:
	frase: ana
	aux = 3/2 = 1 (inteiro)
	primeira iteração: 'a'
	segunda iteração: deve ser 'a' da 2 posição, logo aux+1 = 2.
	*/
	unsigned int end = frase.length()%2 == 0 ? aux : aux+1;

	for (unsigned int i = 0; i < aux; i++) 
		if(frase[i] >= 'a' && frase[i] <= 'z' || frase[i] >= '0' && frase[i] <= '9')
			pilha.empilhar(frase[i]);


	for (unsigned int i = end; i < frase.length(); i++) 
		if(frase[i] >= 'a' && frase[i] <= 'z' || frase[i] >= '0' && frase[i] <= '9')
			if (frase[i] != pilha.desempilhar()) // desempilha e compara as string
				return false;
						
	
	return true;
}

void checkFunction(){
	string ane = "ane";
	string frase1 = "arara";
	string frase2 = "raiar";
	string frase3 = "hanah";
	string frase4 = "Socorram-me, SUBI NO ÔNIBUS EM MARROCOS";

	assert(verificarFrase(ane)==false);
	assert(verificarFrase(frase1));
	assert(verificarFrase(frase2));
	assert(verificarFrase(frase3));
	assert(verificarFrase(frase4));
}


int main(int argc, char const *argv[])
{
	checkFunction();

	bool palindromo = true;
	string frase;
	string original;

	cout << "Insira a frase: ";

	cin.ignore(0, '\n');
	getline(cin, original);

	if (original.length() > 1) {

		frase = original;
		transform(frase.begin(), frase.end(), frase.begin(), ::tolower);

		palindromo = verificarFrase(frase);

		if (palindromo) {
			cout << original << " é palindromo." << endl;
		} else {
			cout << original << " não é palindromo." << endl;
		}


	} else {
		cout << original << " é palindromo." << endl;
	}
	
	
	return 0;
}
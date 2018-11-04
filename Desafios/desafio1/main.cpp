#include "Pilha.h"

#include <iostream>

#include <string>
#include <algorithm> // Transformar string em minuscula

// Remove todos os caracteres especiais e acentuados
void prepararFrase(string& frase) {

	
	frase.erase(std::remove(frase.begin(), frase.end(), '.'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), ','), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '\''), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '\"'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '!'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '@'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '#'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '$'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '%'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '&'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '*'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '('), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), ')'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '-'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '_'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '+'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '-'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '*'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '/'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '\\'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '?'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '{'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '['), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '}'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), ']'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '?'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), ':'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), ';'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), '|'), frase.end());
	frase.erase(std::remove(frase.begin(), frase.end(), ' '), frase.end());

	// replace(frase.begin(), frase.end(), "à", 'a');
	// replace(frase.begin(), frase.end(), "á", 'a'); 
	// replace(frase.begin(), frase.end(), "â", 'a'); 
	// replace(frase.begin(), frase.end(), "ã", 'a'); 
	// replace(frase.begin(), frase.end(), "ç", 'c'); 
	// replace(frase.begin(), frase.end(), "è", 'e');
	// replace(frase.begin(), frase.end(), "è", 'e'); 
	// replace(frase.begin(), frase.end(), "ê", 'e');
	// replace(frase.begin(), frase.end(), "ẽ", 'e');
	// replace(frase.begin(), frase.end(), "í", 'i');
	// replace(frase.begin(), frase.end(), "ì", 'i');
	// replace(frase.begin(), frase.end(), "î", 'i');
	// replace(frase.begin(), frase.end(), "ĩ", 'i');
	// replace(frase.begin(), frase.end(), "ó", 'o');
	// replace(frase.begin(), frase.end(), "ò", 'o');
	// replace(frase.begin(), frase.end(), "ô", 'o');
	// replace(frase.begin(), frase.end(), "õ", 'o');
	// replace(frase.begin(), frase.end(), "ú", 'u');
	// replace(frase.begin(), frase.end(), "ù", 'u');
	// replace(frase.begin(), frase.end(), "û", 'u');
	// replace(frase.begin(), frase.end(), "ũ", 'u');


}




int main(int argc, char const *argv[])
{


	bool palindromo = true;
	string frase;
	string original;

	cout << "Insira a frase: ";

	cin.ignore(0, '\n');
	getline(cin, original);

	if (original.length() > 1) {

		frase = original;

		prepararFrase(frase); // Remove todos os caracteres especiais e acentuados
		
		unsigned int aux = frase.length()/2;
		Pilha<char> pilha(aux);

		transform(frase.begin(), frase.end(), frase.begin(), ::tolower); // Converte a frase para minusculo

		for (unsigned int i = 0; i < aux; i++) { // Empilha metade da: string -> [s, t, r] ou frase [f, r]
			pilha.empilhar(frase[i]);
		}

		if (frase.length()%2 != 0) {
			aux++; // Caso o tamanho da frase seja impar, pula o caracter do centro A - r - [a] - R - a
		}

		for (unsigned int i = aux; i < frase.length(); i++) { // desempilha e compara as string
			if (frase[i] != pilha.desempilhar()){
				palindromo = false;
			}			
		}

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
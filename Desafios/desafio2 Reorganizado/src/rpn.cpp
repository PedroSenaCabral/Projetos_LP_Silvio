#include "Pilha.h"
#include <iostream>
#include <cmath>
#include "rpn.h"
#include <string>
using namespace std;
Rpn::Rpn(){	
}
Rpn::~Rpn(){	
}	

void Rpn::executar(){
	Pilha<int> pilha(50);
	string notacao;
	string notacaoFixa = " ";
	cout << "Insira a expressão no formado Notação Polonesa Inversa: ";

	cin.ignore(0, '\n');
	getline(cin, notacao);



	for (unsigned int i = 0; i < notacao.length(); i++) {
		string aux = "";

		
		while (notacao[i] != ' ' && i < notacao.length()) { // lê cada caracter da string e contatena em 'aux' até encontrar um espaço
			aux += notacao[i];
			i++;
		}

		if (aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/' ) { // Se a leitura do while foi uma operação
			
			// ***** realizar alguma operação ******

			int a = pilha.desempilhar();
			int b = pilha.desempilhar();

			// Os operandos tem que estar invertidos ao  desempilhar. 
			// Assim evita algo do tipo: 10/5 -> 10 5 / ** empilha 10 **> pilha[10] **empilha 5**> pilha[10, 5] ** Desempilhar**> 5 / 10 	
			pilha.empilhar(realizaOperacao(aux[0], b, a));

			if (notacaoFixa.compare(" ") != 0) {

				if (i < notacao.length()) {
					// Não é a ultima operação
					notacaoFixa = "(" + notacaoFixa + aux[0] + to_string(a) + ")";
				} else {
					// É a ultima operação, logo não deve colocar os parenteses
					notacaoFixa = notacaoFixa + aux[0] + to_string(a);
				}
				
			} else {
				notacaoFixa = "(" +to_string(b) + aux[0] + to_string(a) + ")";
			}

		} else { // Se a leitura do while foi um número

			// Pega o valor em string, converte para inteiro com o stoi() e empilha
			pilha.empilhar(stoi(aux));
		
		}

	}

	cout << "\nResultado: " << pilha.desempilhar() << " Infixa: " << notacaoFixa << endl;

}

int Rpn::realizaOperacao(char operacao, int valor1, int valor2) {
	double resultado = 0;
	switch (operacao) {
		case ('+'):
			resultado = valor1 + valor2;
			break;

		case ('-'):
			resultado = valor1 - valor2;
			break;

		case ('*'):
			resultado = valor1 * valor2;
			break;

		case ('/'):
			resultado = valor1 / valor2;
			break;

		default:
			cout << "Operação invalida.";
			exit(0);
	}

	return resultado;
}
<<<<<<< HEAD
#include "Pilha.h"
#include <stack>
=======
#include <stack>
using std::stack;

>>>>>>> 2a62b9ce1a97163594101063a45c50b16c43564a
#include <iostream>

#include <string>
#include <cmath>

using namespace std;

int realizaOperacao(char operacao, int valor1, int valor2) {
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

int main(int argc, char const *argv[])
{

<<<<<<< HEAD
	stack<int> pilha;
=======
	stack<int> s;
>>>>>>> 2a62b9ce1a97163594101063a45c50b16c43564a
	string notacao;
	string notacaoFixa = " ";
	cout << "Insira a expressão no formado Notação Polonesa Inversa: ";

	cin.ignore(0, '\n');
	getline(cin, notacao);



	for (unsigned int i = 0; i < notacao.size(); i++) {
		string aux = "";

		
		while (notacao[i] != ' ' && i < notacao.size()) { // lê cada caracter da string e contatena em 'aux' até encontrar um espaço
			aux += notacao[i];
			i++;
		}

		if (aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/' ) { // Se a leitura do while foi uma operação
			
			// ***** realizar alguma operação ******

<<<<<<< HEAD
			int a = pilha.top();
			pilha.pop();
			int b = pilha.top();
			pilha.pop();
			// Os operandos tem que estar invertidos ao  desempilhar. 
			// Assim evita algo do tipo: 10/5 -> 10 5 / ** empilha 10 **> pilha[10] **empilha 5**> pilha[10, 5] ** Desempilhar**> 5 / 10 	
			pilha.push(realizaOperacao(aux[0], b, a));
=======
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();

			// Os operandos tem que estar invertidos ao  desempilhar. 
			// Assim evita algo do tipo: 10/5 -> 10 5 / ** empilha 10 **> pilha[10] **empilha 5**> pilha[10, 5] ** Desempilhar**> 5 / 10 	
			s.push(realizaOperacao(aux[0], b, a));
>>>>>>> 2a62b9ce1a97163594101063a45c50b16c43564a

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
<<<<<<< HEAD
			pilha.push(stoi(aux));
=======
			s.push(stoi(aux));
>>>>>>> 2a62b9ce1a97163594101063a45c50b16c43564a
		
		}

	}

<<<<<<< HEAD
	cout << "\nReseltado: " << pilha.top();
	pilha.pop();
	cout << " Infixa: " << notacaoFixa << endl;
=======
	cout << "\nReseltado: " << s.top() << " Infixa: " << notacaoFixa << endl;
>>>>>>> 2a62b9ce1a97163594101063a45c50b16c43564a
		
	return 0;
}
#ifndef RPN_H
#define RPN_H
#include <string>
using namespace std;
class Rpn{
private:

public:
	Rpn();
	~Rpn();		
	void executar();
	int realizaOperacao(char operacao, int valor1, int valor2);
};
#endif
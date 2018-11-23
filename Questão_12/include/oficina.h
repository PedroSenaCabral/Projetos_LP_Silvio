#ifndef OFICINA_H
#define OFICINA_H
#define MAX_FUNCIONARIOS 100
#include "funcionario.h"
#include "gerente.h"
#include <string>
class Oficina{
private:
	Funcionario *m_funcionarios[MAX_FUNCIONARIOS];
	Gerente *m_gerente;
	int m_numero_funcionarios;

public:
	Oficina(Gerente *gerente_);
	~Oficina();
	void addFuncionario(Funcionario *funcionario_);
	friend ostream& operator<<(ostream &o, Oficina * of);
};
#endif
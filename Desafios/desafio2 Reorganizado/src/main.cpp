#include "Pilha.h"
#include "rpn.h"
#include <iostream>

using namespace std ;

int main (int argc , char const * argv []){
	Rpn *r = new Rpn();

	r->executar();

return 0;
}
#include <iostream>
#include <algorithm>
#include <set>
using std::set;
using namespace std;


template <typename InputIterator >
void print_elementos(InputIterator first , InputIterator last, const char* label="", const char separator=' ') {
	cout<<label;
	for (auto iterador = first; iterador != last; iterador++){
			cout <<*iterador<<separator;
		}
		cout<<endl;
}

int main(){



set<int> numeros;
numeros.insert(3);
numeros.insert(1);
numeros.insert(4);
numeros.insert(1);
numeros.insert(2);
numeros.insert(5);
numeros.insert(6);
print_elementos(numeros.begin(),numeros.end(), "Set: ");
print_elementos(numeros.begin(),numeros.end(), "CSV Set: ", ';');




	return 0;
}
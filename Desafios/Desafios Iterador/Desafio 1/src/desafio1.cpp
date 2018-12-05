#include <iostream>
#include <algorithm>
#include <set>
using std::set;
using namespace std;
template <typename TContainer>
	void print_elementos(const TContainer& collection, const char* label="", const char separator=' '){
		cout<< label;
		for (auto iterador = collection.begin(); iterador != collection.end(); iterador++){
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
print_elementos(numeros, "Set: ");
print_elementos(numeros, "CSV Set: ", ';');




	return 0;
}
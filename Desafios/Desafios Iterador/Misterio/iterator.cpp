#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename Inputiterator>
Inputiterator misterio(Inputiterator first, Inputiterator last){
	Inputiterator it = std::lower_bound(first, last, std::accumulate(first, last, 0.0)/
	(double) std::distance(first,last));	
	
return it;
}

int main(int argc, char * argv[]){
	vector<int> numeros;
	for(int i = 1; i<=50; i++){
		numeros.push_back(i);
	}
	cout << (*misterio(numeros.begin(),numeros.end()))<<endl;
}
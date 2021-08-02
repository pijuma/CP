#include<bits/stdc++.h>
using namespace std ; 

int qtd ; 

int main(){

	vector<int> f(3) ; 

	cin >> f[0] >> f[1] >> f[2] ; 
	f.push_back(600) ; 

	sort(f.begin(), f.end()) ; 

	int last = 0, qtd = 0 ; 

	for(int i = 0 ; i <= 3 ; i++){
		if(f[i] > last) qtd += (f[i] - last) ; 
		// cout << qtd << " " << last << "\n" ; 
		last = max(last, f[i] + 200) ; 
	}

	cout << qtd*100 << "\n" ; 

}

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 ; 

int n, ehprimo[maxn] ; 
vector<int> divs ; 

void div(){
	for(int i = 2 ; i*i <= n ; i++){
		while(n%i == 0){
			divs.push_back(i) ; 
			n /= i ; 
		}
	}
	if(n > 1) divs.push_back(n) ; 
}

// qtd divs -> p^b * q^g = n -> (b+1)*(g+1) 

int main(){

	cin >> n ; 
	div() ; 
	for(auto a : divs) cout << a << " " ; 
	cout << "\n" ; 

}
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 ; 

int n, ehprimo[maxn] ; 
vector<int> divs ; 

void div(){
     for(int i = 1 ; i*i <= n ; i++){
     	if(n%i) continue ; 
     	if(n/i == i) divs.push_back(i) ; 
     	else divs.push_back(i), divs.push_back(n/i) ; 
     }	
}

int main(){

	cin >> n ; 
	div() ; 
	for(auto a : divs) cout << a << " " ; 
	cout << "\n" ; 

}
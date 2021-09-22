#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, x, pos[maxn], pai[maxn] ; 

int main(){

	vector<int> pilha, v ; 

	cin >> n ; 

	for(int i = 0 ; i < n ; i++){
		cin >> x ; 
		v.push_back(x) ; 
		auto it = lower_bound(pilha.begin(), pilha.end(), x) ; 
		int p = it - pilha.begin() ; 
		if(it == pilha.end()) pilha.push_back(x) ;
		else *it = x ;  
		pos[p] = i ; 
		if(p == 0) pai[i] = -1 ; 
		else pai[i] = pos[p-1] ; 
	}

	vector<int> resp ; 

	cout << pilha.size() << "\n" ; 
	int p = pos[pilha.size() - 1] ; 
	while(p >= 0){
		resp.push_back(v[p]) ; 
		p = pai[p] ; 
	}

	reverse(resp.begin(), resp.end()) ; 

	for(auto a : resp) cout << a << " " ;
	cout << "\n" ; 
}

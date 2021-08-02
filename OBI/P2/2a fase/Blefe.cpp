#include<bits/stdc++.h>
using namespace std ; 

const int maxm = 1e4 + 5 ; 

int n, m, bb[maxm] ; 
bool ok[maxm] ;  

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	vector<int> a(n) ; 
	vector<pair<int,int>> b(m) ;

	for(int i = 0 ; i < n ; i++){
		int num ; 
		cin >> num ; 
		a.push_back(num) ; 
	}

	for(int i = 0 ; i < m ; i++){
		int num ; 
		cin >> num ; 
		bb[i] = num ; 
		b.push_back({num, i}) ; 
	}

	sort(a.begin(), a.end()), sort(b.begin(), b.end()) ; 

	//marcar os q existem em a 

	for(int i = 0, j = 0 ; i < a.size() ; i++){ // quais são iguais a mim em b 

		while(j < b.size() && a[i] > b[j].first) j++ ; 
		while(j < b.size() && a[i] == b[j].first){
			ok[b[j].second] = 1 ; 
			j++ ; 
		}

	}

	for(int i = 0 ; i < b.size() ; i++){ // consigo formar b[k] com b[i] e b[j] ?

		int k = 0 ; 

		for(int j = i ; j < b.size() ; j++){

			while(k < b.size() && b[k].first < b[i].first + b[j].first) k++ ; // se a soma ta maior eu n consigo formar o meu atual ent passo prox 
			while(k < b.size() && b[k].first == b[i].first + b[j].first){
				if(b[k].second > max(b[i].second, b[j].second)) ok[b[k].second] = 1 ; 
				k++ ; 
			}

		}

	}

	for(int i = 0 ; i < m ; i++){

		if(!ok[i]){
			cout << bb[i] << "\n" ; 
			return 0 ; 
		}

	}

	cout << "sim\n" ; 

}

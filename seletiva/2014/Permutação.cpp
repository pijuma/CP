#include<bits/stdc++.h>
using namespace std ; 

// pss manter normal, pular p prox(tirar o anterior)
// mudar e subtrair 1 ou subtrair sem tirar o anterior 

const int maxn = 1e6 + 50 ; 

int n, muda[maxn], fica[maxn], fim[maxn], ini[maxn] ; 
vector<int> grafo[maxn], ans1, ans2 ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(0);

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> ini[i] ; 
	for(int i = 1 ; i < n ; i++) cin >> fim[i] ; 

	for(int i = 1 ; i < n ; i++){
		if(ini[i] == fim[i] || ini[i] - 1 == fim[i]) grafo[ini[i]].push_back(fim[i]) ; 
		if(ini[i+1] == fim[i] || ini[i+1] - 1 == fim[i]) grafo[ini[i+1]].push_back(fim[i]) ; 
	}

	bool sem = 0 ;

	for(int i = 1 ; i <= n ; i++){
		
		if(grafo[i].size() == 0){
			ans1.push_back(i) ; 
			sem = 1 ; 
		}
		
		if(sem) continue ; 

		for(int j = 0 ; j < grafo[i].size() ; j++){
			int a = grafo[i][j] ; 
			if(a == i) fica[i]++ ; 
			if(a == i - 1) muda[i]++ ; 
		}

	}

	for(int i = 1 ; i <= n ; i++) fica[i] += fica[i-1], muda[i] += muda[i-1] ; 

	if(!sem){
		for(int i = 1 ; i <= n ; i++){
		    if(muda[n] - muda[i] == n - i && fica[i-1] == i-1) ans2.push_back(i) ; // se eu tirar o meu n-i vão mudar
		    // q são os maiores e i-1 vão manter
	    }
	} 

	if(sem){
		for(int i = 0 ; i < ans1.size() ; i++) cout << ans1[i] << " " ; 
	}

	else{
		for(int i = 0 ; i < ans2.size() ; i++) cout << ans2[i] << " " ;  
	}

    cout << "\n" ; 

}

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m, r ; 
deque<int> fila[maxn] ; 
vector<pair<int,int>> ans ; 

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		cin >> r ;
		for(int j = 1 ; j <= r ; j++){
			int a ; 
			cin >> a ; 
			fila[i].push_back(a) ;
		}
	}

	for(int i = 2 ; i <= m ; i++){ // tirar da original e levar p 1 
		
		while(!fila[i].empty()){
			int val = fila[i].front() ; 
			fila[i].pop_front() ; 
			ans.push_back({i, 1}) ; 
			fila[1].push_front(val) ; 
		}

	}  

	while(!fila[1].empty()){ // tirar da 1 e jogar na ok ou na 2 (1/2)
		int val = fila[1].front() ; 
		fila[1].pop_front() ; 
		if(val == 1 || val == 2){
			fila[2].push_front(val) ; 
			ans.push_back({1, 2}) ; 
		} 
		else{
			fila[val].push_front(val) ; 
			ans.push_back({1, val}) ;
		} 
	}

	while(!fila[2].empty()){ // pegar na 2 e jogar 1 na 1a e 2 na 3a 
		
		int val = fila[2].front() ; 
		fila[2].pop_front() ; 
		
		if(val == 2){
			fila[3].push_front(val) ; 
			ans.push_back({2, 3}) ; 
		} 
		
		else{
			fila[1].push_front(val) ;
			ans.push_back({2, 1}) ; 
		}   

	}

	while(true){ // tirar os 2's do topo da 3a e jogar na 2a
		if(fila[3].empty()) break ; 
		int val = fila[3].front() ; 
		if(val != 2) break ; 
		fila[3].pop_front() ; 
		ans.push_back({3, 2}) ; 
		fila[2].push_front(2) ;  
	}

	cout << ans.size() << "\n" ; 
	for(auto a : ans) cout << a.first << " " << a.second << "\n" ; 

}

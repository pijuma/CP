#include<bits/stdc++.h>
using namespace std ; 

// qd cai na armadilha fica sem jogar na prox rodada 
// usa uma queue p ver a vez e guarda em q pos ta 
// se der maior ou igual ao final ganhou - queue guarda pos e ind
int p, s, a ; 
map<int, int> mp ; 

int main(){

	while(true){

		cin >> p >> s ; 

		if(!p && !s) return 0 ; 

		mp.clear() ; 

		for(int i = 1 ; i <= 3 ; i++){
			cin >> a ; 
			mp[a] = 1 ; 
		}

		deque<pair<int, pair<int,int>>> jogador ; 
		
		for(int i = 1 ; i <= p ; i++) jogador.push_back({0, {0, i}}) ; 

		int q ; 
		cin >> q ; 

	    int ganhador = 0 ; 
	    bool achei = 0 ; 

	    for(int i = 1 ; i <= q ; i++){
	    	int d1, d2 ; 
	    	cin >> d1 >> d2 ; 
	    	int casas = d1 + d2 ; 
	    	pair<int,pair<int, int>> at = jogador.front() ; jogador.pop_front() ; 
	    	while(true){
	    		   if(at.first != -1) break ; 
	    		   at.first = 0 ; 
	    		   jogador.push_back(at) ; 
	    		   at = jogador.front() ; jogador.pop_front() ; 
	    	}
	    	at.second.first += casas ; 
	    	if(mp.find(at.second.first) != mp.end()) at.first = -1 ; 
	    	if(at.second.first > s && !achei){
	    		ganhador = at.second.second ; 
	    		achei = 1 ; 
	    	}
	    	jogador.push_back(at) ; 
	    }

	    cout << ganhador << "\n" ; 
	}

}

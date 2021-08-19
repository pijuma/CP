#include<bits/stdc++.h>
using namespace std ; 

// n clientes 
// cada um qr um quarto 
// sabemos o dia de entrada e saida de cada 
// qts quartos ? 

int n, qtd, quarto ; 
vector<pair<int,int>> cliente, recuperar ; 
map<pair<pair<int,int>, int>, int> resp ; // guarda o l, r e a freq ja q pode ter varios - quarto 
map<pair<int,int>, int> freq ;  
set<pair<int,int>> s ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		
		int l, r ; 
		cin >> l >> r ; 

		cliente.push_back({l, r}) ;
		recuperar.push_back(cliente[i-1]) ;
	}

	sort(cliente.begin(), cliente.end()) ; 

	for(auto a : cliente){

		freq[a]++ ; 

		auto it = s.lower_bound({-a.first + 1, 0}) ; // qual o 1o quarto q tem algm c saida <= a minha entrada + 1

		if(it != s.end()){ // pss pegar o quarto 
			s.erase(it) ; 
			s.insert({-a.second, (*it).second}) ; 
			resp[{a, freq[a]}] = (*it).second ; 
		}

		else{ // outro quarto 
			s.insert({-a.second, ++quarto}) ; 
			resp[{a, freq[a]}] = quarto ; 
		}

	}

	freq.clear() ; 

	cout << quarto << "\n" ; 

	for(auto a : recuperar) cout << resp[{a, ++freq[a]}] << " " ; 
	cout << "\n" ; 

}

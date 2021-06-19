#include<bits/stdc++.h>
using namespace std ; 

const int maxn =  9999 + 5 ; 

string s ; 
int fi[11], apareceu[11] ; 

bool eh_valido(int c, int qtd){
	
	string k = to_string(c) ; 
	// cout << k << " " << k.size() << "\n" ; 
	if(fi[0] == 0 && k.size() < 4) return 0 ; //eu sou do tipo 0xyz e n posso 0 

	for(int i = 0 ; i < k.size() ; i++){ // tenho algm proibido cmg 
		if(fi[k[i] - '0'] == 0) return 0 ;   
	}

	int oc = 0 ; // tenho tds os caras especiais? 

	for(int i = 0 ; i < 10 ; i++) apareceu[i] = 0 ; 

	for(int i = 0 ; i < k.size() ; i++){
		if(fi[k[i] - '0'] == 1 && apareceu[k[i] - '0'] == 0){
			apareceu[k[i] - '0'] = 1 ; 
			oc++ ; 
			// cout << k[i] << "\n" ; 
		}
	}
	// cout << "\n" ; 
	// cout << c << " " << oc << "\n" ; 
	return (oc == qtd) ; 

}

int main(){

	cin >> s ; 

	for(int i = 0 ; i < s.size() ; i++) fi[i] = 2 ; 

	int o = 0 ; 
    
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'o'){
			fi[i] = 1 ; 
			o++ ; 
		}
		else if(s[i] == 'x') fi[i] = 0 ;  
	}

	// for(int i = 0 ; i < 10 ; i++) cout << f[i] << " " ;
 
	int ans = 0 ; 

	for(int i = 0 ; i <= 9999 ; i++){ // testar tds os numeros e ver se eh valido
		ans += eh_valido(i, o) ; 
	}

	cout << ans << "\n" ; 

}
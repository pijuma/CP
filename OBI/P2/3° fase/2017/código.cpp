#include<bits/stdc++.h>
using namespace std ; 

int n ; 
string s ; 
set<string> suf[12], pref[12] ; 

int main(){

	cin >> n ;

	for(int i = 1 ; i <= n ; i++){

		cin >> s ;
		// checa se é valida
		for(int j = 10 ; j > 0 ; j--){
			string prefixo = s.substr(0, j) ; 
			if(suf[j].count(prefixo) > 0){
				if(j == 10) cout << s << "\n", exit(0) ; 
				else{
					string sufixo = s.substr(j, 10-j) ;
					if(pref[10-j].count(sufixo) > 0) cout << s << "\n", exit(0) ;  
				}
			} 
		}
		// incluia ela
		for(int j = 10 ; j >= 0 ; j--){
			if(j < 10 && j > 0){
				string prefixo = s.substr(0, j) ;
				pref[j].insert(prefixo) ; 
			}
			if(j < 10){
				string sufixo = s.substr(j, 10-j) ; 
				suf[10-j].insert(sufixo) ; 
			}
		}
	} 

	cout << "ok\n" ; 

}

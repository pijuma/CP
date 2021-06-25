#include<bits/stdc++.h>
using namespace std ; 

int n, d, resul ; 
string s ; 

int main(){

	while(true){
		cin >> n ; 
		if(!n) return 0 ; 
		cin >> s ; 

		cout << "Teste " << ++d << "\n" ; 
		
		s = s + '+' ; 

		string num = "" ; 
		char last ; 
		resul = 0 ; 
		last = '+' ; 

		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '+' || s[i] == '-'){
				int numb = stoi(num) ; 
				if(last == '+') resul += numb ; 
				else resul -= numb ;
				num = "" ; 
				last = s[i] ; 
			}
			else num = num + s[i]  ;
		}

		cout << resul << "\n\n" ; 

	}

}

#include<bits/stdc++.h>
using namespace std ; 

int n ; 
char dx[4] = {'N', 'L', 'S', 'O'} ; 
string s ; 

int main(){

	while(true){
		cin >> n ;
		if(!n) return 0 ; 
		cin >> s ; 
		int ct = 0 ; 
		for(int i = 0 ; i < s.size() ; i++){
			ct %= 4 ; 
			if(s[i] == 'E'){
				ct-- ; 
				if(ct < 0) ct = 4 + ct ; 
			} 
			else ct++ ; 
		}
		cout << dx[ct] << "\n" ;
	}

}

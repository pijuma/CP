#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 300 ; 
const int inf = 1e9 ; 

int S, B, s[maxn], b[maxn] ; 

int solve(){
	
	vector<vector<int>> v(S, vector<int>(S)) ; 

	for(int i = 0 ; i < S ; i++){
		if(i == 0) v[0][i] = inf ; 
		else v[0][i] = b[0]*s[i-1] + b[0]*s[i] ; 
	}

	for(int i = 1 ; i < B ; i++){
		
		int a = inf ; 
		
		for(int j = 0 ; j < S ; j++){

			if(j <= 2) v[i][j] = inf ; 

			else{
				a = min(a, v[i-1][j-2]) ;
				if(a == inf) v[i][j] = inf ; 
				else v[i][j] = a + (b[i]*s[j-1] + b[i]*s[j]) ; 
			}

		}

	}

	return v[B-1][S-1] ; 

}

void muda(){
	int a1, a2 ;
	a2 = s[0] ; 
	for(int i = 1 ; i < S ; i++){
		a1 = s[i] ;
		s[i] = a2 ; 
		a2 = a1 ;  
	}
	s[0] = a2 ; 
}

int main(){

	while(true){
		
		cin >> S >> B ; 
		
		if(!S && !B) return 0 ; 
		
		for(int i = 0 ; i < S ; i++) cin >> s[i] ; 
		for(int i = 0 ; i < B ; i++) cin >> b[i] ; 
		
		int resp = inf ; 
	    
	    for(int i = 0 ; i < S ; i++){
	    	int solution = solve() ; 
	    	resp = min(resp, solution) ;
	    	muda() ;  
	    }

	    cout << -resp << "\n" ; 

	}

}

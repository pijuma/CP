#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e6 + 5 ; 

int n, c, p ; 
map<int,int> mp ; 

int main(){

	while(true){

		cin >> n ; 
		if(!n) return 0 ; 
		
		mp.clear() ; 
		bool ok = 1 ; 

		for(int i = 1 ; i <= n ; i++){
			cin >> c >> p ; 
			if(p < 0){
				if(i + p > 0){
					if(mp.find(i+p) == mp.end()) mp[i+p] = c ;
					else ok = 0 ;  
				}
				else ok = 0 ; 
			} 
			else{
				if(i + p <= n){
					if(mp.find(i+p) == mp.end()) mp[i+p] = c ; 
					else ok = 0 ; 
				}
				else ok = 0 ; 
			}
		}

		if(!ok) cout << "-1\n" ; 
		else{
			cout << mp[1] ; 
			for(int i = 2 ; i <= n ; i++) cout << " " << mp[i] ; 
		    cout << "\n" ;
		} 
	}

}

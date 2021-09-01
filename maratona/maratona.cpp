#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 28 ;

int n, a[maxn], ini[maxn], fim[maxn], mn ; 

void solve(){
	
	mn = 0 ; 
	int k = 0 ; 
	int j = 0 ; 

	for(int i = 1 ; i <= n ; i++){
			
			for(j = 1 ; j <= n ; j++){
			    
			    if(ini[i] == fim[j]){

			    	for(k = 1 ; k < i ; k++) a[k] = ini[k] ; 

			        if(ini[i] == fim[1]) mn += (k - 1) ; 
			        else{
			    	
			    	    for(int k = 1 ; k < i ; k++){
			    		 
			    		    bool flag = 0 ; 
			    		
			    	    	for(int f = 1 ; f < j ; f++){
			    		    	if(a[k] == fim[f]) flag = 1 ; 
			    		    }

			    		    if(!flag) mn++ ; 
			    	}

			    }

			    j = n + 1 ; 

			}

		}
	
	}

	cout << mn << "\n" ; 
	return ; 
	
}

int main(){

	while(cin >> n){
		
		for(int i = 1 ; i <= n ; i++) cin >> ini[i] ; 
		for(int i = 1 ; i <= n ; i++) cin >> fim[i] ; 

		solve() ; 
		
	}

}

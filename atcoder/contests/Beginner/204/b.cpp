    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 1e3 + 4 ; 
     
    int n, sum, v[maxn] ;
     
    int main(){
     
    	cin >> n ; 
    	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
    	for(int i = 1 ; i <= n ; i++){
    		if(v[i] < 10) continue ; 
    		sum += (v[i] - 10) ; 
    	}
    	
    	cout << sum << "\n" ;
     
    }

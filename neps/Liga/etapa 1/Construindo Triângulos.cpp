#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, v[maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	sort(v + 1, v + 1 + n) ; 
    
    // a b c - > a < b + c & b < a + c & c < a + b -> maior area possivel 
    
    for(int i = n - 2 ; i > 0 ; i--){
    	if(v[i+2] < v[i] + v[i+1]){
    		cout << v[i] << " " << v[i+1] << " " << v[i+2] << "\n" ; 
    		return 0 ;  
    	}
    }

}

// primos em O(n)
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 3e3 + 5 ; 

int n, low[maxn] ; 
int prim(int n){
	
	vector<int> primos ; 

	for(int i = 2 ; i <= n ; i++){
		
		if(!low[i]){
			low[i] = i ; primos.push_back(i) ;  
		}

		for(int j = 0 ; j < primos.size() && primos[j] <= low[i] && i*primos[j] <= n ; j++) low[i*primos[j]] = primos[j] ; 
		// i = x*pr[i] -> se x pr[x] < pr[i] -> pr[i] n será o menor primo  
	}

	set<int> v ; 
			 
	for(int i = 1 ; i <= n ; i++){
					
		int ct = 0 ; 
			 
		for(int j = 0 ; j < primos.size() ; j++){
			if(primos[j] > i) break ; 
			if(!(i%primos[j])) ct++ ;  
		}
			 
		if(ct == 2) v.insert(i) ; 
			 
	}
			 
	return v.size() ; 
			 
}
			 
int main(){
			 
	cin >> n ; 
	cout << prim(n) << "\n" ; 
			 
}

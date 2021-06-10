#include<bits/stdc++.h>

using namespace std ;

const int maxn = 1e6 + 6 ; 

int n, v[maxn], c[maxn] ;
string s ; 


int main(){

	cin >> n ; 

	cin >> s ; 

	for(int i = 0 ; i < s.size() ; i++) c[i+1] = s[i] ; 

	int sum = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		if(c[i-1] == 'A') sum++ ;
		else if(c[i-1] == 'B') sum-- ; 
		v[i] = sum ;  
	}

	int mn = maxn, ind ; 
	for(int i = 1 ; i <= n ; i++) if(v[i] < mn) mn = v[i], ind = i ; 

	v[ind] = 0 ; 
    sum = 0 ; 

	for(int i = ind ; i > 0 ; i--){
		if(i == ind) continue ; 
		if(c[i] == 'A') sum-- ; 
		if(c[i] == 'B') sum++ ; 
		v[i] = sum ; 
	}

	sum = 0 ; 

	for(int i = ind ; i <= n ; i++){
		if(i == ind) continue ; 
		if(c[i-1] == 'A') sum++ ; 
		else if(c[i-1] == 'B') sum-- ; 
		v[i] = sum ; 
	}

	for(int i = 1 ; i <= n ; i++) cout << v[i] << " " ;
	cout << "\n" ; 

}

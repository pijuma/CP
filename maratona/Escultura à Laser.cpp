#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 

int h, c, v[maxn] ; 

int main(){

	while(true){
		cin >> h >> c ; 
		if(!h && !c) return 0 ; 
		int q = 0 ; 
		for(int i = 1 ; i <= c ; i++) cin >> v[i] ; 
		for(int i = 1 ; i <= c ; i++){
			if(i == 1) q += (h - v[i]) ; 
			else q += max(0, v[i-1] - v[i]) ; 
		}
		cout << q << "\n" ; 
	}

}

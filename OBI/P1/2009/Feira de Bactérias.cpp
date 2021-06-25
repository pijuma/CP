#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 5e4 + 5 ; 

int n, best, c, d ; 
double resp, _log[maxn] ;

int main(){

	resp = 0.0 ; 
	cin >> n ;  

	for(int i = 0 ; i < n ; i++){
		cin >> d >> c ; 
		//d^c se d1^c1 > d2^c2 -> log(d1^c1)  > log(d2^c2) -> log(d1^c1) == c1*logd1 
		if(resp < (double) c*log(d)){
			resp = c*log(d) ; 
			best = i ; 
		}
	}

	cout << best << "\n" ; 

}

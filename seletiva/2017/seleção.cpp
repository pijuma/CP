#include<bits/stdc++.h>
using namespace std ; 

#define ll long long 

const int maxn = 1e6 + 5 ; 

ll n, x[maxn], y[maxn], k, ax, ay, bx, by, cy, cx, my, mx ; 

ll check(ll val){

	long long qtd = 0, ptr = n ; 

	for(int i = 1 ; i <= n ; i++){

		while(ptr > 0 && x[i] + y[ptr] > val) ptr-- ; 
		qtd += ptr ; 

	}

	return qtd ; 
	
}

ll bb(){ // bb no valor 
	
	ll ini = 0 , fim = 1e9 + 10 , mid, best = 1 ; 
	
	while(ini <= fim){
		mid = (ini + fim)/2 ; 
		if(check(mid) >= k) best = mid, fim = mid - 1 ; 
		else ini = mid + 1 ; 
	}

	return best ; 

}

int main(){

	cin >> n >> k ; 

	cin >> ax >> bx >> cx >> mx ; 
	cin >> ay >> by >> cy >> my ; 

	x[1] = ax, y[1] = ay ; 

	for(int i = 2 ; i <= n ; i++){
		x[i] = (bx + cx*x[i-1])%mx ; 
	}

	for(int i = 2 ; i <= n ; i++){
		y[i] = (by + cy*y[i-1])%my ; 
	}

	sort(x + 1, x + 1 + n) ; 
	sort(y + 1, y + 1 + n) ; 
  
	cout << bb() << "\n" ; 

}

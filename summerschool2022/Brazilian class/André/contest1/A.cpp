#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

// brute force até 3*(n+1) - 1a vez q pega casa d outro se n acontecer nunca acontecerá 

int n, vs, vb, vl, p1, ans, mx[maxn], vis[maxn], qtd_vis[maxn], p2, p3 ; 
bool flag = 0 ; 

void go(int &p, int qtd, int type){

	p = (p+qtd)%(n+1) ; 

	if(p == 0) return ; 

	if(vis[p] == 0){

		vis[p] = type ;
		qtd_vis[type] = 0 ; 
		mx[type]++ ; 

	}

	else if(vis[p] == type) qtd_vis[type]++ ; 

	else flag = 1 ; 

}

bool cant(){

	if(flag) return 1 ; 

	for(int i = 1 ; i <= 3 ; i++) if(qtd_vis[i] <= mx[i]) return 0 ; 

	return 1 ; 

}

int main(){

	cin >> n >> vs >> vb >> vl ; 

	while(true){

		go(p1, vs, 1) ; ans++ ; 
		if(cant()) break ;  

		go(p2, vb, 2) ; ans++ ; 
		if(cant()) break ;  

		go(p3, vl, 3) ; ans++ ; 
		if(cant()) break ;  

	}

	if(flag) cout << ans << "\n" ; 
	else cout << "3000000000\n" ; 

}

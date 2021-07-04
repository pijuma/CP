#include<bits/stdc++.h>
#define ll long long 
#define int long long
using namespace std ; 

const int inf = 1e9 + 15 ; 
const int maxn = 1e3 + 5 ; 

struct P{

	int x, y ; 

	P operator - (P a){ return P { x - a.x, y - a.y } ; } 
	P operator + (P a){ return P {x + a.x, y  + a.y} ; } 

	ll operator % (P a){ return x*a.y - y*a.x ; } // cross -> sen
	ll operator * (P a) {return x*a.x + y*a.y ; } 

} ; 

int n, m ; 
P p[maxn] ; 

bool onseg(P a, P b, P c){ return (c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) && c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y)) ; }

int orient(P a, P b, P c){ 
	return (a-b)%(c-b) ; 
}

bool iscol(P a, P b, P c){
	
	int o1 = orient(a, b, c) ; 

	if(o1 == 0 && onseg(a, b, c)) return true ; 
	
	return false ; 

 
}

bool bounda(P a){

	for(int i = 1 ; i <= n ; i++){
		int j = (i%n) + 1, k = ((i+1)%n) + 1 ; 
		// cout << j << " " << k << "\n" ; 
		if(iscol(p[j], p[k], a)) return true ; 
	}

	return false ; 

}

bool cruza(P a, P b, P c, P d){

	int o1 = orient(a, b, c) ; 
	int o2 = orient(a, b, d) ; 
	int o3 = orient(c, d, a) ; 
	int o4 = orient(c, d, b) ; 

	if(o1 > 0) o1 = 1 ; 
	else o1 = 2 ; 
	if(o2 > 0) o2 = 1 ; 
	else o2 = 2 ; 
	if(o3 > 0) o3 = 1 ; 
	else o3 = 2 ; 
	if(o4 > 0) o4 = 1 ; 
	else o4 = 2 ; 

	if(o1 != o2 && o3 != o4) return true ; 

	return false ; 

}

bool isin(P a){

	P ex = {inf, a.y} ; 

	int ct = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		int j = (i%n) + 1, k = ((i+1)%n) + 1 ; 
		ct += cruza(a, ex, p[j], p[k]) ; 
	}
	
	// cout << ct << "\n" ; 

	return (ct%2) ; 

}

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i].x >> p[i].y ;

	for(int i = 1 ; i <= m ; i++){ 

		int x, y ; 
		cin >> x >> y ; 
		
		P f = {x, y} ; 

		if(bounda(f)){
			cout << "BOUNDARY\n" ; 
			continue ; 
		}

		cout << (isin(f) ? "INSIDE" : "OUTSIDE") << "\n" ;  

	} 

}

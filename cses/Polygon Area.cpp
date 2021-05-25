#include<bits/stdc++.h>

#define ll long long 
#define sz size 
#define f first 
#define s second 
#define pii pair<ll, ll>
using namespace std ; 

const int maxn = 1005 ; 

pii p[maxn] ;
int n ; 

long long cross(pii a, pii b){ return a.f*b.s - a.s*b.f ;}

long long area(){
	
	long long ans = 0 ; 
	
	for(int i = 3 ; i <= n ; i++){
		pii a = {p[i].f - p[1].f, p[i].s - p[1].s} ; 
		pii b = {p[i-1].f - p[1].f, p[i-1].s - p[1].s} ;
		ans += cross(a, b) ; 
	}

	return abs(ans) ; 

}

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i].f >> p[i].s ; 

	cout << area() << "\n" ; 

}

#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int> 
#define f first 
#define s second 
using namespace std ; 

const int maxn = 1005 ; 

int n ; 
pii p[maxn] ;

int cross(pii a, pii b){ return a.f*b.s - a.s*b.f ; }

//soma tds as areas dos triangulos 
//area do triangulo -> cross/2 

int area(){
	int ar = 0 ; 
	for(int i = 3 ; i <= n ; i++){
		pii a = {p[i].f - p[1].f, p[i].s - p[1].s} ;
		pii b = {p[i-1].f - p[1].f, p[i-1].s - p[1].s} ; 
		ar += cross(a, b) ;  
	}
	return abs(ar) ; 
}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i].f >> p[i].s ; 
	cout << area() << "\n" ; 

}
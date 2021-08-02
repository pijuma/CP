#include<bits/stdc++.h>
#define int long long 
using namespace std ;

const int maxn = 3e5 + 5 ; 

int n ; 

struct P{

	int x, y ; 

	P(int x = 0 , int y = 0) : x(x), y(y) { } ; 

	P operator - (P a) const { return P({x - a.x, y - a.y}) ; }

	int operator % (P a){ return (x*a.y)-(y*a.x) ; }

	bool operator < (P a){return x < a.x ; }
} ;

P pontos[maxn] ; 

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> pontos[i].x >> pontos[i].y ; 

	sort(pontos + 1, pontos + n + 1) ; 
	vector<P> ans ; 
	
	for(int i = 1 ; i <= n ; i++){
		while(ans.size() > 1 && ((ans[ans.size() - 1] - ans[ans.size() - 2])%(pontos[i] - ans[ans.size() - 2])) >= 0) ans.pop_back() ; 
		ans.push_back(pontos[i]) ; 
	}

	cout << ans.size() - 1 << "\n" ; 
} 

#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first 
#define y second
using namespace std ;  

const int maxn = 2e3 + 15 ; 

int n, qtd ; 
set<int> mark ; 
pair<pair<int,int>,int> p[maxn] ; 

pii sub(pair<pii, int> a, pair<pii, int> b){ return {a.x.x - b.x.x, a.x.y - b.x.y} ; }

int cross(pii a, pii b){ return a.x*b.y - a.y*b.x ; }

vector<pair<pii,int>> convex() {

	vector<pair<pii, int>> hull, up, low ; 

	for(int i = 1 ; i <= n ; i++){
		if(mark.find(p[i].y) != mark.end()) continue ; 
		while(up.size() > 1 && cross(sub(up.back(), up[up.size() - 2]), sub(p[i], up[up.size() - 2])) > 0) up.pop_back() ;
		up.push_back(p[i]) ;
	}

	for(int i = 1 ; i <= n ; i++){
		if(mark.find(p[i].y) != mark.end()) continue ; 
		while(low.size() > 1 && cross(sub(low.back(), low[low.size() - 2]), sub(p[i], low[low.size() - 2])) < 0) low.pop_back() ;
		low.push_back(p[i]) ;
	}

	for(auto a : up) hull.push_back(a) ; 
	for(auto a : low) hull.push_back(a) ; 

	return hull ; 
} 

void solve(){

	mark.clear() ;
	qtd = 0 ; 

	while(true){
		vector<pair<pii, int>>  hull = convex() ; 
		if(hull.size() <= 2) break ;
		qtd++ ;
		for(auto a : hull)  mark.insert(a.y) ; 
	}

    if(qtd&1) cout << "Take this onion to the lab!\n" ; 
    else cout << "Do not take this onion to the lab!\n" ;

}

int main(){

	while(true){

		cin >> n ; 
		if(!n) return 0 ; 

		for(int i = 1 ; i <= n ; i++) cin >> p[i].x.x >> p[i].x.y, p[i].y = i ;

		sort(p + 1, p + 1 + n) ; 

	    solve() ; 

	}

}

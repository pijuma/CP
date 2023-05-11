// https://br.spoj.com/problems/CEBOLA/
#include<bits/stdc++.h>
using namespace std ; 

#define pii pair<int,int> 
#define piii pair<int,pair<int,int>> 

const int maxn = 2e3 + 5 ; 

int n, ct ;  
bool mark[maxn] ; 
vector<piii> pto ; 

int cross(pii a, pii b){ return a.first*b.second - a.second*b.first ; }
pii sub(piii a, piii b){ return {a.first - b.first, a.second.first - b.second.first} ; }

bool hull(){

	vector<piii> pt ; 

	for(int i = 0 ; i < n ; i++) if(mark[i] == 0) pt.push_back(pto[i]) ; 

	if(pt.size() == 0) return 0 ; 

    sort(pt.begin(), pt.end()) ; 

	vector<piii> up, low ;

	for(int i = 0 ; i < pt.size() ; i++){
		while(up.size() > 1 && cross(sub(up[up.size()-1], up[up.size()-2]), sub(pt[i], up[up.size()-2])) < 0) up.pop_back() ; 
		up.push_back(pt[i]) ; 
	}

	for(int i = 0 ; i < pt.size() ; i++){
		while(low.size() > 1 && cross(sub(low[low.size()-1], low[low.size()-2]), sub(pt[i], low[low.size()-2])) > 0) low.pop_back() ; 
		low.push_back(pt[i]) ;
	}

	for(auto a : up) mark[a.second.second] = 1 ; 
	for(auto a : low) mark[a.second.second] = 1 ; 

	return 1 ; 

}

void solve(){

	vector<piii> up, low ; 

	pto.clear() ; 

	ct = 0 ; 

	for(int i = 0 ; i < n ; i++) mark[i] = 0 ; 

	for(int i = 0 ; i < n ; i++){
		int x, y ; cin >> x >> y ; 
		pto.push_back({x, {y, i}}) ; 
	}

	while(1){
		bool miss = hull() ; 
		if(!miss) break ; 
		ct++ ; 
	}

	if(ct&1) cout << "Take this onion to the lab!\n" ; 
	else cout << "Do not take this onion to the lab!\n" ; 

}

int main(){

	while(1){
		cin >> n ; 
		if(n == 0) break ; 
		solve() ; 
	}

}

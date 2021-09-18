#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

// ta crescente na pos 
// S'0 + v't = S0 + vt - achar tempo de colisão

long long n, pos[maxn], v[maxn] ;
map<int,int> colidiu ; 
set<int> caras ; 

struct F{

	long long num, den ; 

	bool operator < (F c) const{ return (num*c.den) < (den*c.num) ; }

} ;

set<pair<F, pair<int, int>>> tempos ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> pos[i] >> v[i] ; 

	for(int i = 1 ; i <= n ; i++){
		caras.insert(i) ; 
		if(i != n){
			if(v[i] == v[i+1]) continue ;  
			int a = (pos[i+1] - pos[i]), b = (v[i] - v[i+1]) ; 
			F c = {a, b} ; 
			if(b > 0) tempos.insert({c, {i, i+1}}) ;  
		}
	}

	while(true){

		if(tempos.empty()) break ; 

		auto t = (*tempos.begin()) ; 
		int a = t.second.first, b = t.second.second ; 
		tempos.erase(*tempos.begin()) ; 

		if(colidiu.find(a) != colidiu.end() || colidiu.find(b) != colidiu.end()) continue ; 

		else{
			if(colidiu.find(a) == colidiu.end()) caras.erase(a) ;
			if(colidiu.find(b) == colidiu.end()) caras.erase(b) ; 
			auto next = caras.upper_bound(b), ant = caras.upper_bound(a) ; 
			if(colidiu.find(a) == colidiu.end() && colidiu.find(b) == colidiu.end()) colidiu[a] = colidiu[b] = 1 ; 
			if(ant != caras.begin()) ant-- ; 
			else continue ; 
			if(next != caras.end() && ant != next){
				if(v[(*ant)] == v[(*next)]) continue ;
				int aa = (pos[(*next)] - pos[(*ant)]), bb = (v[(*ant)] - v[(*next)]) ;  
				// cout << aa << " " << bb << "\n" ; 
				F c = {aa, bb} ; 
			    if(bb > 0) tempos.insert({c, {(*ant), (*next)}}) ;
			}
		}

	}

	vector<int> ans ; 

	for(int i = 1 ; i <= n ; i++){
		if(colidiu.find(i) == colidiu.end()) ans.push_back(i) ; 
	}

	cout << ans.size() << "\n" ; 

	if(ans.size() != 0){
		for(auto a : ans) cout << a << " " ; 
	    cout << "\n" ; 
    } 

}

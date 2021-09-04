#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

struct tripla{
	int z, x, y ; 
} ; 

int n, t ; 
tripla v[maxn] ; 

bool cmp(tripla p, tripla s){ return p.z <= s.z ; }

struct P{

	set<pair<int,int>> s ; 

	void clean(){ s.clear() ; }

	int add(tripla v){

		pair<int,int> at = {v.x, v.y} ; 

		auto it = s.upper_bound(at) ; // 1o cara c x maior (n tem igual n desempata)

		if(it != s.end() && (*it).second > at.second) return 0 ; // n pss add pq perco

		// s n tem ng ou pode add

		vector<pair<int,int>> eraser ; 
		while(it != s.begin()){ // enquanto der p tirar 
			it-- ; 
			if((*it).second > at.second) break ; 
		    eraser.push_back(*it) ; 
		} 

		for(auto a : eraser) s.erase(a) ; 
		s.insert(at) ; 

		return 1 ; // n é perdedor
	}

} pareto ; 

int main(){

	cin >> t ; 

	while(t--){
		
		pareto.clean() ; 

		cin >> n ; 
		
		for(int i = 1 ; i <= n ; i++){
			int a, b, c ; 
			cin >> a >> b >> c ; 
			a = n - a, b = n - b, c = n - c ; 
			v[i] = {a, b, c} ; 
		}

		sort(v + 1, v + 1 + n, cmp) ; 

		// qd for add eu checo se o 1o q tem x maior q o meu tem y maior tb 
		// se sim n add pq perdi
		// se n tiver ng ou eu n perder eu add mas tenho q retirar antes tds os q tem x imediatamente menor
		// que o meu e tem y menor pois eu ganho deles 
		// assim n serão mais uteis
		int ans = 0 ; 

		for(int i = n ; i > 0 ; i--){ // se eu perder é p algm q eu ja add q tem y e x maior
			ans += pareto.add(v[i]) ; 
		}

		cout << ans << "\n" ; 

	}

}

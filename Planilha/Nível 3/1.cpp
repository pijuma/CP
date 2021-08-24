// B. Mr. Kitayuta's Colorful Graph
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 110 ; 

int n, q, m, mark[maxn] ; 
vector<int> colors ; 
vector<pair<int,int>> grafo[maxn] ; 

void dfs(int v, int cor){

	mark[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a.second != cor || mark[a.first]) continue ; 
		dfs(a.first, cor) ; 
	}

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ; 
		colors.push_back(c) ; 
		grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ;
	}

	sort(colors.begin(), colors.end()) ; colors.erase(unique(colors.begin(), colors.end()), colors.end()) ; 

	cin >> q ; 

	while(q--){
		
		int u, v ; 
		cin >> u >> v ;

		int resp = 0 ;

		for(int i = 0 ; i < colors.size() ; i++){
			for(int i = 1 ; i <= n ; i++) mark[i] = 0 ; 
			dfs(u, colors[i]) ; //consigo ir p v so usando cor i 
		    if(mark[v] == 1) resp++ ; 
		}

		cout << resp << "\n" ; 

	}

}

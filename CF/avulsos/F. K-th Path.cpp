// qual o kesimo menor caminho 
#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int inf = 1e18 ; 
const int maxk = 1200 ; 

int n, m, k ; 
int d[maxk][maxk] ;
map<int,int> id ; 
vector<int> p ; 
map<int, bool> cmp ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m >> k ;

	for(int i = 0 ; i < 1000 ; i++){

		for(int j = 0 ; j < 1000 ; j++){
			d[i][j] = inf ;
			if(i == j) d[i][j] = 0 ;  
		}

	}

	vector<pair<int,pair<int,int>>> e ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ; 
		a--, b-- ; 

		e.push_back({c, {a, b}}) ; 

	}

	sort(e.begin(), e.end()) ; 

	for(int i = 0 ; i < min(k, (int)e.size()) ; i++){ // queremos o kesimo menor -> n precisa mais q k 
		cmp[e[i].second.first] = 1 ; cmp[e[i].second.second] = 1 ; 
	}

	int ID = 0 ; 

	for(auto a : cmp) id[a.first] = ID++ ; 

	for(int i = 0 ; i < min(k, (int)e.size()) ; i++){
		int a, b ; 
		a = id[e[i].second.first], b = id[e[i].second.second] ; 
		d[a][b] = d[b][a] = e[i].first ; 
	}

	for(int k = 0 ; k < ID ; k++){ // floyd w. 
		
		for(int i = 0 ; i < ID ; i++){

			for(int j = 0 ; j < ID ; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]) ; 
			}

		}

	}

	for(int i = 0 ; i < ID ; i++){

		for(int j = i + 1 ; j < ID ; j++){
			p.push_back(d[i][j]) ; 
		}

	}

	sort(p.begin(), p.end()) ; 

	cout << p[k-1] << "\n" ; 

}

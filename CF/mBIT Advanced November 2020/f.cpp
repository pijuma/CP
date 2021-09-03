#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, m, k, b, ans, vis[maxn][maxn] ; 
string s ; 

int dx[4] = {0, 0, 1, -1} ; // dir, esq, p baixo, p cima 
int dy[4] = {1, -1, 0, 0} ; 

vector<pair<int,int>> cand[4] ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

int32_t main(){

	cin >> n >> m >> k >> b ; 
	cin >> s ; 

	for(int i = 1 ; i <= k ; i++){
		int a, b ; 
		cin >> a >> b ; 
		vis[a][b] = 1 ;
		for(int j = 0 ; j < 4 ; j++) cand[j].push_back({a, b}) ; 
	}

	ans = k ; 
	// cand[j] tds velas q podem mover com o vento j 
	// qd bate eu tenho q att só daql movimento das outras n mas devo add as novas velas 
	// q podem ser afetadas pelos novos ventos
	for(int i = 0 ; i < s.size() ; i++){
		
		int d ; 
		if(s[i] == 'E') d = 0 ; 
		else if(s[i] == 'W') d = 1 ; 
		else if(s[i] == 'N') d = 3 ; 
		else d = 2 ; 
		
		vector<pair<int,int>> new_cand ; 

		for(auto at : cand[d]){
			int ati = at.first + dx[d], atj = at.second + dy[d] ; 
			if(!valid(ati, atj) || vis[ati][atj]) continue ; 
			vis[ati][atj] = 1 ; 
			new_cand.push_back({ati, atj}) ; 
			ans++ ; 
		}

		cand[d].clear() ; 

		for(int j = 0 ; j < 4 ; j++){
			for(int l = 0 ; l < new_cand.size() ; l++) cand[j].push_back(new_cand[l]) ;
		} 

		cout << ans << "\n" ; 
	}

}

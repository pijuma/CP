#include<bits/stdc++.h>
using namespace std ; 

// move p onde ta virado
// qd vai p baixo muda p lado oposto 
// n° min p cortar td (W)
// começa (1, 1) virado p dir 

const int maxn = 155 ; 
const int inf = 1e9 ; 

int n, m, ans ; 
char grid[maxn][maxn] ; 
vector<pair<int,int>> grama ; 

bool cmp(pair<int,int> a, pair<int,int> b){

	if(a.first != b.first) return a.first < b.first ; 
	if(a.first&1) return a.second < b.second ;
	return a.second > b.second ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> grid[i][j] ; 
			if(grid[i][j] == 'W') grama.push_back({i, j}) ; 
		}
	}

	sort(grama.begin(), grama.end(), cmp) ; 

	int posi = 1, posj = 1 ; 

	for(int i = 0 ; i < grama.size() ; i++){
		ans += abs(posi - grama[i].first) + abs(posj - grama[i].second) ;
		posi = grama[i].first, posj = grama[i].second ;  
	}

	cout << ans << "\n" ; 
	
}

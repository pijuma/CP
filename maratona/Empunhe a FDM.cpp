#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, m, grid[maxn][maxn], grid2[maxn][maxn], dir[maxn][maxn] ; 

struct MQ{

	deque<pair<int,int>> mq ; 
	int ini, fim ;

	void Mq(){
		mq.clear() ; 
		ini = 1, fim = 0 ; 
	}

	void add(int val){
		while(!mq.empty() && mq.back().first >= val) mq.pop_back() ; 
		mq.push_back({val, ++fim}) ;
	}

	void remove(){
		if(!mq.empty() && mq.front().second == ini++) mq.pop_front() ; 
	}

	int get(){ return mq.front().first ; }

} mnq ; 

bool check(int val){

	// fixar a coluna 
	for(int j = 1 ; j <= m ; j++){
		
		mnq.Mq() ;  
		for(int i = 1 ; i <= val ; i++) mnq.add((dir[i][j])) ;
		int mn = mnq.get() ; 
	    if(mn >= val) return 1 ; 
		for(int i = val + 1 ; i <= n + 1 ; i++){
			int valor_min = mnq.get() ; 
			if(valor_min >= val) return 1 ; 
			mnq.remove() ; 
			mnq.add((dir[i][j])) ; 
		}

	}

	return 0 ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			char a ; 
			cin >> a ; 
			grid[i][j] = (a == 'G') ;
		}
	}

	// histograma p linhas 
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = m ; j >= 1 ; j--){
			if(grid[i][j] == grid[i][j+1]) dir[i][j] = dir[i][j+1] + 1 ; 
			else dir[i][j] = 1 ; 
		} 
 	}

	int ini = 1, fim = min(m, n), mid, best = 1 ; 

	while(ini <= fim){
		mid = (ini + (fim - ini)/2) ; 
		//mid = (ini + fim)/2 ;
		
		if(check(mid)){
			best = mid ; 
			ini = mid + 1 ; 
		}
		
		else fim = mid - 1 ; 

	}

	cout << (best)*(best) << "\n" ; 

}

#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxn = 2e5 + 5 ;

//sorta pelo inicio 
//começa do 1 
//faz mlr entre pegar e ir p upper_bound -1  ou nn pegar

ll dp[maxn] ; 
int n ; 
vector< pair<pair<ll, ll>, ll> > v ; 

int bb(int pos){ //1o cara q tem ini maior q pos 

	int ini = 0, fim = n-1, mid, best = n + 1 ; 

	while(ini <= fim){
		mid = (ini + fim)/2 ; 
		if(v[mid].first.first <= pos) ini = mid + 1 ; 
		else best = mid, fim = mid - 1 ; 
	}

	return best ; 

}

ll solve(int pos){
	if(dp[pos] != -1) return dp[pos] ; 
	int newpos = bb(v[pos].first.second) ; 
	return dp[pos] = max(solve(pos + 1), solve(newpos) + v[pos].second) ; 
}

int main(){

	ll ini, fim, ganho ; 

	cin >> n ; 

	for(int i = 0 ; i < n ; i++){
		cin >> ini >> fim >> ganho ;
		v.push_back({{ini, fim}, ganho}) ;  
		dp[i] = -1 ; 
	}

	sort(v.begin(), v.end()) ;  

	cout << solve(0) << "\n" ; 

}

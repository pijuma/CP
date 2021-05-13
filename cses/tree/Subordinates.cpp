#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, dp[maxn] ; 
vector<int> grafo[maxn] ; 
 
void dfs(int v){
	dp[v] = 0 ; 
	for(int a : grafo[v]){ 
		dfs(a) ; 
		dp[v] = (dp[v] + dp[a] + 1); 
	}
 
}
 
int main(){
 
	cin >> n ; 
 
	for(int i = 2 ; i <= n ; i++){
		int a ; 
		cin >> a ; 
		grafo[a].push_back(i) ;  
	}
 
	dfs(1) ; 
 
	for(int i = 1 ; i <= n ; i++) cout << dp[i] << " " ; 
	cout << "\n" ; 
 
}

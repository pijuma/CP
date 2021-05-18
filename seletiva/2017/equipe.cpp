#include<bits/stdc++.h>
using namespace std ; 

const int inf = 1e8 ; 
const int maxn = 201 ; 

int dp[(1<<12)][(1<<12)], tem[maxn], ntem[maxn] ; 
int n, k, m, v ; 

int solve(int i, int maskon, int maskof){

	if(maskof == (1<<k) - 1 && maskon == (1<<k) - 1) return 0 ; //fechou a equipe 
	if(i > n) return inf ; // n tem mas qm visitar e n formou grupo bom 
	if(dp[maskon][maskof] != -1) return dp[maskon][maskof] ; // ja calculou 
	
	// cout << i << ":\n" ; 
	// cout << maskon << " " << maskof << "\n" ; 

	int newon = maskon | tem[i], newof = maskof | ntem[i] ; 
	return dp[maskon][maskof] = min(solve(i+1, maskon, maskof), solve(i+1, newon, newof) + 1) ; // min entre pegar e n pegar
}

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++){
		
		cin >> m ; 
		
		ntem[i] = (1<<k) - 1 ; 

		while(m--){
			cin >> v ; 
			tem[i] |= (1<<(v-1)) ; 
		}

		ntem[i] ^= tem[i] ; //desliga tds que tem assim resta os q n tem  

	}

	// for(int i = 1 ; i <= n ; i++) cout << tem[i] << " " << ntem[i] << "\n" ; 

	memset(dp, -1, sizeof dp) ; 

	int ans = solve(1, 0, 0) ; 

	if(ans > n) cout << "-1\n" ; 
	else cout << ans << "\n" ; 

}

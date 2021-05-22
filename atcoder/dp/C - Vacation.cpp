#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, a[maxn], b[maxn], c[maxn], dp[4] ; 

// dp[a] guarda a ultima atv do tipo a 
// n pode pegar no msm dia 
// ent pegamos smp p cada atv ela mais a mlr op entre pegra a do tipo i ou j 
// e pegamos a mlr op ao final de tudo entre as 3 atvs 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> b[i] >> c[i] ; 
	}

	dp[1] = a[1], dp[2] = b[1], dp[3] = c[1] ; 

	for(int i = 2 ; i <= n ; i++){
		int dpn[4] ; 
		dpn[1] = a[i] + max(dp[3], dp[2]) ; 
		dpn[2] = b[i] + max(dp[1], dp[3]) ; 
		dpn[3] = c[i] + max(dp[1], dp[2]) ; 
		dp[1] = dpn[1], dp[2] = dpn[2], dp[3] = dpn[3] ; 
	}

	cout << max({dp[1], dp[2], dp[3]}) << "\n" ; 

}

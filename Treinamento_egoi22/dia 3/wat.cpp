// https://dmoj.ca/problem/joi13op3
// vc qr ver n eventos o evento i será na sec ai 
// p cameras pequenas e q grandes 
// camera pequena tira ft de w e grande de 2w 
// min w 
// dp[n][p][q]
// dp[i][j] - ql min de cameras grandes q ele precisa pra chegar ate i com j pequenas
#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e3 + 2 ; 
const int inf = 1e16 + 5 ; 

int n, p, q ; 
int v[maxn], dp[maxn][maxn], jmpw[maxn], jmp2w[maxn] ; 

int bb(int i, int j, int k){
	v[n+1] = inf ; 
	int ini = i, fim = j+1, mid, best = i + 1 ; 
	while(ini <= fim){
		mid = (ini + fim)/2 ; 
		int d = v[mid] - v[i] + 1 ; 
		if(d > k) best = mid, fim = mid - 1 ; 
		else ini = mid + 1 ; 
	}
	return best ; 
}

int solve(int i, int j, int jmp){
	if(j > p) return inf ; 
	if(i > n) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ; 
	int where_w = jmpw[i], where_2w = jmp2w[i] ; 
	// pss usar pequena ou a grande 
	return dp[i][j] = min(solve(where_w, j+1, jmp), solve(where_2w, j, jmp) + 1) ;  
}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> p >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	if(p + q >= n){
		cout << "1\n" ; exit(0) ; 
	}

	sort(v + 1, v + 1 + n) ; 

	int ini = 1, fim = v[n] + 1, mid, best = 0 ; 

    while(ini <= fim){
    	mid = (ini + fim)>>1 ; 
    	memset(dp, -1, sizeof dp) ; 
    	for(int i = 1 ; i <= n ; i++) jmpw[i] = bb(i, n, mid), jmp2w[i] = bb(i, n, 2*mid) ; 
    	if(solve(1, 0, mid) <= q) best = mid, fim = mid - 1 ;
    	else ini = mid + 1 ; 
    }

    cout << best << "\n" ; 

}

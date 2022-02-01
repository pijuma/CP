#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 100 ; 
int t, dp[maxn][3][12] ; 
string n ; 

// dp[i][j][k] - i pos, j - bool, k - maior usado 

int dp_solve(int i, bool flag, int mx){

	if(i == (int)n.size()) return 1 ; 
	if(dp[i][flag][mx] != -1) return dp[i][flag][mx] ; 

	int ans = 0 ; 

	if(flag){ // ja consegui ser menor so tenho q usar numeros >= mx 
		for(int j = mx ; j < 10 ; j++) ans += dp_solve(i+1, 1, j) ;  
	}

    else{
    	for(int j = 0 ; j < (n[i] - '0') ; j++){
    		if(j < mx) continue ; 
    		ans += dp_solve(i+1, 1, j) ; 
    	}
    	if(n[i] - '0' >= mx) ans += dp_solve(i+1, 0, n[i]-'0') ;  
    }

    return dp[i][flag][mx] = ans ; 

}

int solve(string n){

	memset(dp, -1, sizeof dp) ; 

	return dp_solve(0, 0, 0) ; 

}

bool is_ramp(){

	for(int i = 0 ; i < (int)n.size() - 1 ; i++){
		if(n[i] > n[i+1]) return 0 ;  
	}

	return 1 ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> t ; 

	while(t--){

		cin >> n ; 

		if(!is_ramp()){
			cout << "-1\n" ;  
		}

		else cout << solve(n) - 1 << "\n" ; 

	}

}

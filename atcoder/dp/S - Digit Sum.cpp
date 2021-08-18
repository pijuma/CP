#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 10001 ; 
const int mod = 1e9 + 7 ; 

int d, pos, dp[maxn][110][2], mark[maxn][110][2] ; 
string n ; 
vector<int> num ; 

// posição, resto da divisão da soma por d, flag 
int solve(int i, int s, bool flag){

	if(i == pos) return !s ; 
	if(mark[i][s][flag] != -1) return dp[i][s][flag] ; 

	mark[i][s][flag] = 1 ; 

	int resp = 0 ; 

	if(flag){ // pss colocar qlqr numero 
		for(int j = 0 ; j < 10 ; j++) resp += solve(i + 1, (s + j)%d, 1) ; 
	}
    
    else{
    	for(int j = 0 ; j < num[i] ; j++) resp += solve(i + 1, (s + j)%d, 1) ; 
    	resp += solve(i + 1, (s + num[i])%d, 0) ; 
    }

    resp %= mod ; 

    return dp[i][s][flag] = resp ; 

}

int create(string x){

	num.clear() ; 

	for(int i = 0 ; i < x.size() ; i++) num.push_back(x[i] - '0') ; 
    
    memset(mark, -1, sizeof mark) ; 

    int resp = 0 ; 

    return (solve(0, 0, 0) - 1 + mod)%mod ; 

}

int32_t main(){

	cin >> n >> d ; 

	pos = n.size() ; 

	cout << create(n) << "\n" ; 

}

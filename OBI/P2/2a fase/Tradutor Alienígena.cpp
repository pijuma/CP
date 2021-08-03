#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int mod = 1e9 + 7 ; 
const int maxn = 1e5 + 5 ; 

int dp[maxn] ; 
string n, s ; 

bool valid(string menor, string maior){ // menor eh menor q maior ?

	if(menor.size() != maior.size()) return maior.size() > menor.size() ; 

	for(int i = 0 ; i < menor.size() ; i++){

		if(menor[i] - '0' > maior[i] - '0') return 0 ; 
		if(menor[i] - '0' < maior[i] - '0') return 1 ; 

	}

	return 0 ; 

}

int solve(int idx){

	if(dp[idx] != -1) return dp[idx] ; 

	int ans = 0 ; 
	string num ; 

	for(int i = idx ; i < s.size() ; i++){ // onde eu quebro pro prox n°

		num = num + s[i] ; 

		if(s[i+1] == '0') continue ; // vai de 1 a n 
		if(!valid(num, n)) break ; //se num > k -> invalido

		ans = (ans + solve(i + 1))%mod  ; //coloquei ate i no meu n°
	
	}

	return dp[idx] = ans ? ans : valid(num, n) ; // n cortar -> pegar o ultimo n° sozin 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
	 
	cin >> n >> s ; 

	for(int i = 0 ; i <= s.size() ; i++) dp[i] = -1 ; 

	cout << solve(0) << "\n" ; 

}

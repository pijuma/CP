#include<bits/stdc++.h>
 
#define ll long long 
 
using namespace std ; 
 
vector <int> num ; 
long long dp[10][19][2][2] ; 
 
ll solve(int last, int pos, bool null, bool flag, int numb){
	
	if(pos == num.size()) 
		return 1 ; 
 
	if(dp[last][pos][null][flag] != -1) return dp[last][pos][null][flag] ; 
 
	ll tot = 0 ; 
 
	if(flag){
	
		for(int i = 0 ; i < 10 ; i++){
			if(last == i && i == 0 && !null) continue ; 
			if(last == i && i) continue ;
			tot += solve(i, pos + 1, null&(i==0), 1, 10*numb + i) ; 
		}
	
	}
 
	else{
 
		for(int i = 0 ; i < num[pos] ; i++){
			if(last == i && i == 0 && !null) continue ; 
			if(last == i && i) continue ; 
			tot += solve(i, pos + 1, null&(i==0), 1, 10*numb + i) ; 
		}
 
		if(num[pos] == 0 && last == 0 && null) tot += solve(num[pos], pos + 1, (num[pos]==0)&null, 0, 10*numb + num[pos]) ; 
		else if(num[pos] != last) tot += solve(num[pos], pos + 1, (num[pos]==0)&null, 0, 10*numb + num[pos]) ; 
 
	}
 
	return dp[last][pos][null][flag] = tot ; 
 
}
 
ll calc(ll x){
	
	if(x < 0) return 0 ; 
 
	num.clear() ;
 
	while(x){
		num.push_back(x%10) ; 
		x /= 10 ; 
	}
 
	reverse(num.begin(), num.end()) ; 
 
	memset(dp, -1, sizeof dp) ; 
 
	return solve(0, 0, 1, 0, 0) ; 
 
}
 
int main(){
 
	ll a, b ; 
 
	cin >> a >> b ; 
 
	cout << calc(b) - calc(a-1) << "\n" ; 
 
}

#include<bits/stdc++.h>
using namespace std ;

const int maxn = 2e5 + 5 ; 

int n, x[maxn], Bit[maxn], dp[maxn] ; 
vector<int> b, v ; 

struct BIT{

	void att(int pos, int val){
		for( ; pos < maxn ; pos += pos&-pos) Bit[pos] = max(Bit[pos], val) ; 
	}

    int query(int pos){
    	int tot = 0 ; 
    	for( ; pos > 0 ; pos -= pos&-pos) tot = max(tot, Bit[pos]) ; 
    	return tot ; 
    }

} bit ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> x[i] ; 
		v.push_back(x[i]) ; 
	}

	sort(v.begin(), v.end()) ; 
	v.erase(unique(v.begin(), v.end()), v.end()) ; 

	for(int i = 1 ; i <= n ; i++){
		x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1 ;
		// cout << x[i] << " " ; 
		dp[i] = bit.query(x[i]-1) + 1 ;
		// cout << dp[i] << " " ; 
		bit.att(x[i], dp[i]) ;  
	}

	cout << bit.query(n) << "\n" ; 

}

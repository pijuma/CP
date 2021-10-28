#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int maxn = 1e6 + 5 ; 
const int mod = 1e9 + 7 ; 
const int prime = 37 ; 
 
int inv[maxn], pot[maxn], p[maxn] ; 
string s ; 
 
int exp(int a, int b){
 
	if(!b) return 0 ; 
 
	int ans = 1 ; 
 
	while(b){
		if(b&1) ans = (ans*a)%mod ; 
		a = (a*a)%mod ; 
		b >>= 1 ; 
	}
 
	return ans ; 
 
}
 
int32_t main(){
 
	cin >> s ; 
 
	inv[0] = pot[0] = 1LL ; 
	inv[1] = exp(prime, mod-2) ; 
 
	for(int i = 1 ; i < maxn ; i++) pot[i] = (pot[i-1]*prime)%mod ; 
	for(int i = 2 ; i < maxn ; i++) inv[i] = (inv[i-1]*inv[1])%mod ; 
 
	p[0] = (s[0]-'a'+1) ; 
    
    for(int i = 1 ; i < s.size() ; i++) p[i] = (p[i-1] + (pot[i]*(s[i]-'a'+1))%mod)%mod ; 
 
    vector<int> ans ; 
 
    for(int i = 0 ; i < s.size() - 1 ; i++){
    	int val = p[i] ;
    	val = (val+mod)%mod ; 
    	val = (val*inv[0])%mod ; 
    	int pos = s.size() - 1 - i ; 
    	int val2 = p[s.size()-1] ;  
    	if(pos) val2 -= p[pos-1] ; 
    	val2 = (val2+mod)%mod ; 
    	val2 = (val2*inv[pos])%mod ; 
    	if(val == val2) ans.push_back(i) ; 
    } 
 
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] + 1 << " " ; 
    cout << "\n" ; 
 
}

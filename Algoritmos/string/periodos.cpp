#include<bits/stdc++.h>
#define int long long 
using namespace std ;
 
const int maxn = 1e6 + 5 ; 
const int prime = 37 ; 
const int mod = 1e9 + 7 ; 
 
int pot[maxn], inv[maxn], p[maxn] ; 
string s ; 
vector<int> ans ; 
 
int exp(int a, int b){
 
	if(!b) return 1 ; 
 
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
 
	pot[0] = inv[0] = 1LL ; 
	inv[1] = exp(prime, mod-2) ; 
 
	for(int i = 1 ; i < maxn ; i++) pot[i] = (pot[i-1]*prime)%mod ; 
	for(int i = 2 ; i < maxn ; i++) inv[i] = (inv[i-1]*inv[1])%mod ; 
 
	p[0] = (s[0]-'a'+1) ; 
    
    for(int i = 1 ; i < s.size() ; i++) p[i] = (p[i-1] + ((s[i]-'a'+1)*pot[i])%mod)%mod ; 
 
	for(int i = 1 ; i <= s.size() ; i++){
		bool ok = 1 ; 
		// cout << i << ":\n" ;  
		for(int j = 0 ; j < s.size() ; j+=i){
			// cout << j << " " << i + j - 1 << "\n" ; 
			if(i + j - 1 >= s.size()){
				int val = p[(int)s.size()-1] ; 
				if(j) val -= p[j-1] ; 
				val = (val+mod)%mod ; 
				val = (val*inv[j])%mod ;
				int tam = i+j-1-((int)s.size()-1) ;  
				tam = i-tam ; 
				int val_2 = p[tam-1] ; 
				if(val != val_2) ok = 0 ; 
			}
			else{
				int val = p[j+i-1] ; 
			    if(j) val -= p[j-1] ;
			    val = (val + mod)%mod ; 
			    val = (val*inv[j])%mod ; 
			    if(val != p[i-1]) ok = 0 ; 
			}  
		}
		// cout << "\n" ; 
		if(ok) ans.push_back(i) ; 
	}
 
	for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 
 
}

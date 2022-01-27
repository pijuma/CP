// n precisa de bit pode usar um array simples
#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int mod = 1e9 + 7 ; 
const int prime = 911382323 ; 
const int maxn = 1e6 ; 
 
 
int n, m, t, inv[maxn], pot[maxn], other ; 
int bit1[maxn], bit2[maxn] ;
string s ; 
 
int exp(int a, int b){
 
	int ans = 1 ; 
 
	if(b == 0) return 1LL ; 
 
	while(b){
		if(b&1) ans = (ans*a)%mod ; 
		a = (a*a)%mod ; 
		b >>= 1 ; 
	}
 
	return ans ; 
 
}
 
struct BIT{
 
	void upd(int pos, int v){
		for(; pos < maxn ; pos += pos&-pos) bit1[pos] = (bit1[pos] + v)%mod ; 
	}
 
	int query(int pos){
		int tot = 0 ; 
		for(; pos > 0 ; pos -= pos&-pos) tot = (tot + bit1[pos])%mod ; 
		return tot ; 
	}
 
} Bit1 ; 
 
struct BIT2{
 
	vector<int> bit ; 
 
	void upd(int pos, int v){
		for(; pos < maxn ; pos += pos&-pos) bit2[pos] += v ; 
	}
 
	int query(int pos){
		int tot = 0 ; 
		for(; pos > 0 ; pos -= pos&-pos) tot += bit2[pos] ; 
		return tot ; 
	}
 
} Bit2 ;
 
bool pal(int l, int r){
 
	int val = Bit1.query(r+1) ; 
	if(l) val -= Bit1.query(l) ;  
	val = ((val%mod)+mod)%mod ; 
	val = (val*inv[l+1])%mod ; 
 
	int ri = s.size() - l - 1, li = s.size() - r - 1 ; 
 
	int val2 = Bit2.query(ri+1) ; 
	if(li) val2 -= Bit2.query(li) ; 
	val2 = ((val2%mod)+mod)%mod ; 
	val2 = (val2*inv[li+1])%mod ; 
 
	return val == val2 ; 
 
}
 
void make_str(string p){
 
	for(int i = 0 ; i < p.size() ; i++){
		Bit1.upd(i+1, (pot[i]*(p[i]-'a'+1))%mod) ;
		Bit2.upd(p.size()-i, (pot[p.size()-i-1]*(p[i]-'a'+1))%mod) ;
	}
 
}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	int tt ; 
	cin >> tt ; 
 
	pot[0] = inv[0] = 1LL ; 
    inv[1] = exp(prime, mod-2) ; 
 
	for(int i = 1 ; i < maxn ; i++) pot[i] = (pot[i-1]*prime)%mod ; 
	for(int i = 2 ; i < maxn ; i++) inv[i] = (inv[i-1]*inv[1])%mod ;
 
	for(int j = 0 ; j < tt ; j++){

		cin >> s ; 
 
		memset(bit1, 0, sizeof bit1) ; memset(bit2, 0, sizeof bit2) ; 
 
	    make_str(s) ; 
 
	    bool ans = 0 ; 
	    for(int i = 0 ; i < s.size() - 1 ; i++){
	    	if(pal(0, i) && pal(i+1, s.size()-1)){
	    		cout << "alindrome\n" ; 
	    		ans = 1 ; 
	    		break ;  
	    	}
	    }
 
	    if(!ans && pal(0, (int)s.size()-1)) cout << "palindrome\n" ; 
	    else if(!ans) cout << "simple\n" ; 
 
	}
 
}

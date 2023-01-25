#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int prime = 31 ; 
const int maxn = 3e5 + 5 ; 
const int mod = 1e9 + 7 ; 
 
int n, m, pref[maxn], pot[maxn], inv[maxn] ; 
string s ; 
int bit1[maxn], bit2[maxn] ;  
 
struct BIT{
 
	void upd(int pos, int v){
		for(; pos < maxn ; pos += pos&-pos) bit1[pos] += v ; 
	}
 
	int query(int pos){
		int tot = 0 ; 
		for(; pos > 0 ; pos -= pos&-pos) tot += bit1[pos] ; 
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
 
void change(string at, int pos, char neww){
	
	int val = (pot[pos]*(at[pos]-'a'+1))%mod ;
	
	Bit1.upd(pos+1, -val) ; 
	Bit1.upd(pos+1, (pot[pos]*(neww-'a'+1))%mod) ; 
 
	int rpos = at.size() - 1 - pos ;  
 
	Bit2.upd(rpos+1, -(pot[rpos]*(at[pos]-'a'+1))%mod) ;
	Bit2.upd(rpos+1, (pot[rpos]*(neww-'a'+1))%mod) ; 
 
}
 
void make_str(string p){
 
	for(int i = 0 ; i < p.size() ; i++){
		Bit1.upd(i+1, (pot[i]*(p[i]-'a'+1))%mod) ;
		Bit2.upd(p.size()-i, (pot[p.size()-i-1]*(p[i]-'a'+1))%mod) ;
	}
 
}
 
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
 
 
bool pal(int l, int r){
 
	int val = Bit1.query(r+1) ; 
	if(l) val -= Bit1.query(l) ; 
	val = (val+mod)%mod ; 
	val = (val*inv[l+1])%mod ; 
 
	int ri = s.size() - l - 1, li = s.size() - r - 1 ; 
 
	int val2 = Bit2.query(ri+1) ; 
	if(li) val2 -= Bit2.query(li) ; 
	val2 = (val2+mod)%mod ; 
	val2 = (val2*inv[li+1])%mod ; 
 
	return val == val2 ; 
 
}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> m ; 
 
	cin >> s ; 
 
	pot[0] = inv[0] = 1LL ; 
	inv[1] = exp(prime, mod-2) ; 
 
	for(int i = 1 ; i < maxn ; i++) pot[i] = (pot[i-1]*prime)%mod ; 
	for(int i = 2 ; i < maxn ; i++) inv[i] = (inv[i-1]*inv[1])%mod ; 
 
	make_str(s) ;  
 
	for(int i = 1 ; i <= m ; i++){
		int tipo, a, x ;
		char b ;  
		cin >> tipo ;
		if(tipo == 1){
			cin >> a >> b ;
			a-- ;  
			change(s, a, b) ; 
			s[a] = b ; 
		}
		else{
			cin >> a >> x ;
			a--, x-- ;  
			cout << (pal(a, x) ? "YES\n" : "NO\n") ; 
		}
	}
 
}

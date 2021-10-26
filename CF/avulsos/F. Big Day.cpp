// 1 hashing para cada string 
// para palindromo seria unir checa se na ordem normal e invertido tem a msm "soma" 

#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 3e5 + 5 ; 
const int mod = 1e9 + 7 ; 
const int prime = 37 ; 

int pot[maxn], inv[maxn], n, q, p[maxn] ;
vector<int> bit1[maxn], bit2[maxn] ;  
string s[maxn] ; 

struct BIT{

	void upd(int id, int pos, int v){
		for(; pos < s[id].size() + 5  ; pos += pos&-pos) bit1[id][pos] += v ; 
	}

	int query(int id, int pos){
		int tot = 0 ; 
		for(; pos > 0 ; pos -= pos&-pos) tot += bit1[id][pos] ; 
		return tot ; 
	}

} Bit1 ; 

struct BIT2{

	vector<int> bit ; 

	void upd(int id, int pos, int v){
		for(; pos < s[id].size() + 5 ; pos += pos&-pos) bit2[id][pos] += v ; 
	}

	int query(int id, int pos){
		int tot = 0 ; 
		for(; pos > 0 ; pos -= pos&-pos) tot += bit2[id][pos] ; 
		return tot ; 
	}

} Bit2 ;

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

void make_str(string p, int id){

	for(int i = 0 ; i < p.size() ; i++){
		Bit1.upd(id, i+1, (pot[i]*(p[i]-'a'+1))%mod) ;
		Bit2.upd(id, p.size()-i, (pot[p.size()-i-1]*(p[i]-'a'+1))%mod) ;
	}

}

void change(string at, int id, int pos, char neww){
	
	int val = (pot[pos]*(at[pos]-'a'+1))%mod ;
	
	Bit1.upd(id, pos+1, -val) ; 
	Bit1.upd(id, pos+1, (pot[pos]*(neww-'a'+1))%mod) ; 

	int rpos = at.size() - 1 - pos ;  

	Bit2.upd(id, rpos+1, -(pot[rpos]*(at[pos]-'a'+1))%mod) ;
	Bit2.upd(id, rpos+1, (pot[rpos]*(neww-'a'+1))%mod) ; 

}

int Get_val(int id, int li, int ri){
	
	int val = Bit1.query(id, ri + 1) ; 
	if(li) val -= Bit1.query(id, li) ; 
	
	val = (val+mod)%mod ; 
	val = (val*inv[li+1])%mod ; 

	return val ; 
}

int Get_val2(int id, int li, int ri){
	
	int val = Bit2.query(id, ri + 1) ; 
	if(li) val -= Bit2.query(id, li) ; 
	
	val = (val+mod)%mod ; 
	val = (val*inv[li+1])%mod ; 

	return val ; 
}

bool check(int id, int id2, int li, int ri, int lj, int rj){

	int val = Get_val(id, li, ri) ;  

	int val2 = Get_val(id2, lj, rj) ; 

	return val == val2 ; 

}

bool pal(int id, int id2, int li, int ri, int lj, int rj){

	// checar se bit1(li, ri) + pot[ri-li+1]*bit1(lj, rj) 
    // é igual a bit2(lj, rj) + pot[rj-lj+1]*bit2(li, ri) 

    // cout << li << " " << ri << " " << lj << " " << rj << "\n" ; 

	int val = Get_val(id, li, ri) ;  

	int val2 = Get_val(id2, lj, rj) ; 

	int t = (val + (pot[ri-li+1]*val2)%mod)%mod; 

	int fimi = s[id].size() - li - 1, inii = s[id].size() - ri - 1 ; 
	int fimj = s[id2].size() - lj - 1, inij = s[id2].size() - rj - 1 ; 

	int v_inv = Get_val2(id, inii, fimi) ; 
	int v_inv2 = Get_val2(id2, inij, fimj) ; 

	int t2 = (v_inv2 + (pot[fimj-inij+1]*v_inv)%mod)%mod ;   
	return t == t2 ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> q ; 

	inv[0] = pot[0] = 1LL ; 
	inv[1] = exp(prime, mod-2) ; 

	for(int i = 1 ; i < maxn ; i++) pot[i] = (pot[i-1]*prime)%mod ; 
	for(int i = 2 ; i < maxn ; i++) inv[i] = (inv[i-1]*inv[1])%mod ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> s[i] ; 
		bit1[i].resize(s[i].size()+5), bit2[i].resize(s[i].size()+5) ; 
		make_str(s[i], i) ; 
	}

	while(q--){
	
		int type, i, j, li, lj, ri, rj ; 
		char c ; 
	
		cin >> type ; 
	
		if(type == 1){
			cin >> i >> j >> c ; 
			j-- ; 
			change(s[i], i, j, c) ; 
			s[i][j] = c ; 
		}

		else if(type == 2){
			cin >> i >> j >> li >> ri >> lj >> rj ; 
			cout << (check(i, j, li-1, ri-1, lj-1, rj-1) ? "equal\n" : "different\n") ;  
		}
		
		else{
			cin >> i >> j >> li >> ri >> lj >> rj ; 
			cout << (pal(i, j, li-1, ri-1, lj-1, rj-1) ? "cool\n" : "not so cool\n") ; 
		}
	
	}

}

#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 9e5 + 5 ; 

int n, q, v[maxn], bit[maxn], a[maxn], b[maxn] ; 
char t[maxn] ;

vector<int> valor ; 

struct BIT{

	void upd(int pos, int val){
		for(; pos < maxn ; pos += pos&-pos) bit[pos] += val ; 
	}

	int query(int pos){
	
		int tot = 0 ; 
	
		for(; pos > 0 ; pos -= pos&-pos) tot += bit[pos] ; 
	
		return tot ; 

	}

} Bit ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= q ; i++) cin >> t[i] >> a[i] >> b[i] ; 

	for(int i = 1 ; i <= n ; i++) valor.push_back(v[i]) ; 

	for(int i = 1 ; i <= q ; i++){
		if(t[i] == '?') valor.push_back(a[i]) ; 
		valor.push_back(b[i]) ; 
	}

	sort(valor.begin(), valor.end()) ; 
	valor.erase(unique(valor.begin(), valor.end()), valor.end()) ; 

	for(int i = 1 ; i <= n ; i++) v[i] = lower_bound(valor.begin(), valor.end(), v[i]) - valor.begin() + 1 ; 

	for(int i = 1 ; i <= q ; i++){
		if(t[i] == '?') a[i] = lower_bound(valor.begin(), valor.end(), a[i]) - valor.begin() + 1 ; 
		b[i] = lower_bound(valor.begin(), valor.end(), b[i]) - valor.begin() + 1 ; 
	}

	for(int i = 1 ; i <= n ; i++) Bit.upd(v[i], 1) ; 

	for(int i = 1 ; i <= q ; i++){
		
		if(t[i] == '?') cout << Bit.query(b[i]) - Bit.query(a[i] - 1) << "\n" ; 
		
		else{
			Bit.upd(v[a[i]], -1) ; 
			v[a[i]] = b[i] ; 
			Bit.upd(v[a[i]], 1) ; 
		}

	}

}

// otimização com bit 
#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, h[maxn], b[maxn], bit[maxn] ; 

struct BIT{

	void upd(int pos, int val){
		for(; pos < maxn ; pos += pos&-pos) bit[pos] = max(bit[pos], val) ; 
	}
    
    int query(int pos){
    	int tot = 0 ; 
    	for(; pos > 0 ; pos -= pos&-pos) tot = max(tot, bit[pos]) ; 
    	return tot ; 
    }

} Bit ; 

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> h[i] ; 

	for(int j = 1 ; j <= n ; j++) cin >> b[j] ; 

	int mx = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		Bit.upd(h[i], Bit.query(h[i]) + b[i]) ; 
		mx = max(mx, Bit.query(h[i])) ; 
	}

	cout << mx << "\n" ; 

}

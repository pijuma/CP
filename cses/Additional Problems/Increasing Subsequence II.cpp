#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 9e5 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, v[maxn], bit[maxn], resp ;  
vector<int> valor ; 

struct BIT{

	void upd(int pos, int val){
		for( ; pos < maxn ; pos += pos&-pos) bit[pos] = (bit[pos] + val)%mod ;
	}

    int query(int pos){
    	
    	int tot = 0 ; 

    	for(; pos > 0 ; pos -= pos&-pos) tot = (tot + bit[pos])%mod ; 

    	return tot ; 

    }

} Bit ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		 cin >> v[i] ; 
		 valor.push_back(v[i]) ; 
	}

	sort(valor.begin(), valor.end()) ; 
	valor.erase(unique(valor.begin(), valor.end()), valor.end()) ; 

	for(int i = 1 ; i <= n ; i++) v[i] = lower_bound(valor.begin(), valor.end(), v[i]) - valor.begin() + 1 ; 

	for(int i = 1 ; i <= n ; i++){
		int sub = 1 + Bit.query(v[i] - 1) ; 
		resp = (resp + sub)%mod ; 
		Bit.upd(v[i], sub) ;   
	} 

	cout << resp << "\n" ; 

}

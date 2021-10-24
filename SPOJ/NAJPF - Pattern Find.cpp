#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e6 + 5 ; 
const int mod = 1e9 + 7 ; 
const int prime = 37 ; 

int n, m, t, p[maxn], inv[maxn], pot[maxn], other ; 
string a, b ; 

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

void solve(){

	cin >> a >> b ; 

	n = a.size(), m = b.size() ;

	p[0] = ((a[0]-'a')+1) ;
    
    for(int i = 1 ; i < n ; i++) p[i] = (p[i-1]+((a[i]-'a'+1)*pot[i])%mod)%mod ;

    other = (b[0]-'a'+1) ; 
    for(int i = 1 ; i < m ; i++) other = (other + ((b[i]-'a'+1)*pot[i])%mod)%mod ; 

    vector<int> ans ;  

    for(int i = 0 ; i + m - 1 < n ; i++){
    	int val = p[i+m-1] ; 
    	if(i) val -= p[i-1] ; 
    	val = (val + mod)%mod ; 
    	val = (val*inv[i])%mod ; 
    	if(val == other) ans.push_back(i) ;
    }

    if(ans.size() == 0) cout << "Not Found\n" ; 
    else{
    	cout << ans.size() << "\n" ; 
    	for(auto a : ans) cout << a + 1 << " " ; 
    	cout << "\n" ; 
    }

    cout << "\n" ; 
}

int32_t main(){ 

	pot[0] = 1LL ; 

	for(int i = 1 ; i < maxn ; i++) pot[i] = (pot[i-1]*prime)%mod ; 

	inv[0] = 1LL ; 
    inv[1] = exp(prime, mod - 2) ; 

    for(int i = 2 ; i < maxn ; i++) inv[i] = (inv[i-1]*inv[1])%mod ; 

    cin >> t ; 

    while(t--) solve() ; 

}

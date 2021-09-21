#include<bits/stdc++.h>

#define ll long long 
#define int long long 

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 5e5 + 5 ; 

ll p, q ;
int n ; 
ll bit[maxn] ; 

struct SEG{

	void att(int pos){
		for( ; pos < maxn ; pos += (pos&-pos)) bit[pos] += 1 ; 
	}

	long long query(int pos){
        ll sum = 0 ; 
        for(; pos > 0 ; pos -= (pos&-pos)) sum += bit[pos] ; 
        return sum ; 
    }

} seg ; 

int32_t main(){

	pair<ll, ll> v[maxn] ; 
	ll ans ; 
	
	vector<ll> deltas ; 

	cin >> n >> p >> q ; 

	if(q < 0) q *= -1LL, p *= -1LL ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> v[i].first >> v[i].second ; 
		deltas.push_back(q*v[i].second - p*v[i].first) ; 
	}

	sort(deltas.begin(), deltas.end()) ; 

	deltas.erase(unique(deltas.begin(), deltas.end()), deltas.end()) ; 

	sort(v + 1, v + 1 + n) ; 

	for(int i = 1 ; i <= n ; i++){
		ll k ;
		k = q*v[i].second - p*v[i].first ;
		k = upper_bound(deltas.begin(), deltas.end(), k) - deltas.begin() ; 
		ans += seg.query(k) ; 
		seg.att(k) ; 
	}

	cout << ans << "\n" ; 

}

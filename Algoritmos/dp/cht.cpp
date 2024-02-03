#include<bits/stdc++.h>
#define ll long long 
#define int long long 
#define sz size
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
const int inf = 1e18 + 5 ; 
 
int pos[maxn], pref[maxn], v[maxn], lst_time[maxn], speed[maxn] ;
int n, q ; 
 
struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use INF = 1/.0, div(a,b) = a/b)
  static const ll INF = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = INF;
      return false;
    }
    if (x->k == y->k) {
      x->p = x->m > y->m ? INF : -INF;
    } else {
      x->p = div(y->m - x->m, x->k - y->k);
    }
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) {
      z = erase(z);
    }
    if (x != begin() && isect(--x, y)) {
      isect(x, y = erase(y));
    }
    while ((y = x) != begin() && (--x)->p >= y->p) {
      isect(x, erase(y));
    }
  }
  ll query(ll x) const {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
} cht;
 
// vou do i pro j (i <= j)
// i*v[i] + pref[i-1] (fixo) + j*v[i] - pref[j-1]
// j*v[i] - pref[j-1] = a*x + b -> cht passa a e b query chama x 
// j crescente
// x = v[i]
int32_t main(){
 
    cin >> n ; int initial = 0 ; 
 
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
    for(int i = 1 ; i <= n ; i++) initial += (v[i]*i); 
 
    int ans = initial ; 
 
    for(int i = 1 ; i <= n ; i++) pref[i] = pref[i-1] + v[i] ; 
 
    for(int i = 1 ; i <= n ; i++){
        cht.add(i, -pref[i-1]) ;   
        ll mov = cht.query(v[i]) ;
        ans = max(ans, initial + mov - i*v[i] + pref[i-1]) ;
    }
 
    cht.clear() ;
 
    for(int i = n ; i >= 1 ; i--){
        cht.add(i, -pref[i]) ;
        ll mov = cht.query(v[i]) ;
        ans = max(ans, mov + initial - i*v[i] + pref[i]) ;
    }
 
    cout << ans << "\n" ; 
 
}

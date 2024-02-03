#include <bits/stdc++.h>
#define ll long long 
#define int long long 
using namespace std ; 
 
const int maxn = 3e3 + 5 ;
const long long MOD = 1e9 + 7;
 
int D, n ;  
vector<int> grafo[maxn] ;
ll dp[maxn][maxn] ;
ll fat[maxn], ifat[maxn];

ll exp(ll a, ll b) {
	ll ans = 1 ; 
    while(b){
        if(b&1) ans = (ans*a)%MOD ;
        a = (a*a)%MOD ; b>>=1 ;
    }
    return ans ;
}

class LagrangePoly {
public:
	LagrangePoly(std::vector<long long> _a) {
		//f(i) = _a[i]
		//interpola o vetor em um polinomio de grau y.size() - 1
		y = _a;
		den.resize(y.size());
		int n = (int) y.size();
		for(int i = 0; i < n; i++) {
			y[i] = (y[i] % MOD + MOD) % MOD;
			den[i] = ifat[n - i - 1] * ifat[i] % MOD;
			if((n - i - 1) % 2 == 1) {
				den[i] = (MOD - den[i]) % MOD;
			}
		}
	}
	
	long long getVal(long long x) {
		int n = (int) y.size();
		x %= MOD;
		if(x < n) {
			//return y[(int) x];
		}
		std::vector<long long> l, r;
		l.resize(n);
		l[0] = 1;
		for(int i = 1; i < n; i++) {
			l[i] = l[i - 1] * (x - (i - 1) + MOD) % MOD;
		}
		r.resize(n);
		r[n - 1] = 1;
		for(int i = n - 2; i >= 0; i--) {
			r[i] = r[i + 1] * (x - (i + 1) + MOD) % MOD;
		}
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			long long coef = l[i] * r[i] % MOD;
			ans = (ans + coef * y[i] % MOD * den[i]) % MOD;
		}
		return ans;
	}
	
private:
	vector<ll> y, den;
};

int solve_dp(int v, int p, int mx){

    if(mx <= 0) return 0 ; 
    //if(grafo[v].size() == 1 && p != -1) return mx ; 
    if(dp[v][mx] != -1) return dp[v][mx] ; 

    int ans = solve_dp(v, p, mx-1) ; //usar mx-1 em v 

    int prod = 1 ; 
    int ok = 1 ; 

    for(auto a : grafo[v]){
        if(a == p) continue ; 
        ok = 0 ; 
        prod = (prod*solve_dp(a, v, mx))%MOD ; 
    }

    if(ok) return dp[v][mx] = mx ; 

    return dp[v][mx] = (ans + prod)%MOD ; 
}

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    fat[0] = 1 ; ifat[0] = 1 ;

    cin >> n >> D ;

    for(int i = 1 ; i < maxn ; i++){
        fat[i] = (fat[i-1]*i)%MOD ; 
        ifat[i] = exp(fat[i], MOD-2) ; 
    }

    memset(dp, -1, sizeof(dp)) ;

    for(int i = 2 ; i <= n ; i++){
        int p ; cin >> p ; 
        grafo[p].push_back(i) ; grafo[i].push_back(p) ;
    }

    int degree = n+5 ; 
    vector<ll> vals ; 

    for(int d = 0 ; d < degree ; d++){
        vals.push_back(solve_dp(1, -1, d)) ;
    }

    LagrangePoly la(vals) ; 

    cout << la.getVal(D) << "\n" ; 

}

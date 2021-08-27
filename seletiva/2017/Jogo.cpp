#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 3e3 + 5 ; 
const int inf = 1e18 ; 

struct Pt{
	long long x, y, val ; 
} ; 

Pt pt[maxn] ;
int n ;  

bool cmp(Pt a, Pt b){ return a.x < b.x ; }

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> pt[i].x >> pt[i].y >> pt[i].val ; 

	sort(pt + 1, pt + 1 + n, cmp) ; //ordena do menor p maior x 

    int ans = -inf ; 

    for(int i = 1 ; i <= n ; i++){

    	map<double, long long> mp ; 

    	for(int j = 1 ; j <= n ; j++){
    		
    		if(j == i || pt[j].x < pt[i].x) continue ; //evita pegar repetido pego j smp sendo pto dps
    		
    		double t1 = pt[i].x - pt[j].x ; 
    		double t2 = pt[i].y - pt[j].y ; 

    		if(t1 == 0.00) mp[inf] += pt[j].val ; // novo kra fica c a tg /0 cmg ent add no inf o valor dele
    		else mp[t2/t1] += pt[j].val ; //mais um kra com a tg t2/t1

    		if(t1 == 0.00) ans = max(ans, mp[inf] + pt[i].val) ; //add o kra q eu fixei e tento maximizar o ans
    		else ans = max(mp[t2/t1] + pt[i].val, ans) ; 

    	}
    }

    cout << ans << "\n" ; 

}

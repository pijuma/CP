    #include<bits/stdc++.h>
    #define ll long long 
    using namespace std ;
     
    const int maxn = 3e5 + 3 ; 
     
    ll n, a[maxn], ans ;
    pair<ll, ll> v[maxn] ;
     
    // precisamos pegar a soma de tds as vzs que o valor i 
    // serÃ¡ o maximo 
    // e fazer o msm p minimo 
     
    ll calc(){
     
    	int fim = 1 ;
    	ll sum = 0, now = 0 ;  
    	for(int i = 1 ; i <= n ; i++){
     
    		while(fim > 1 && v[fim].second < a[i]){
    			now -= 1LL*(v[fim].first - v[fim - 1].first) * v[fim].second ; 
    			fim-- ; 
    		}
     
    		now += 1LL*(i - v[fim].first) * a[i] ; 
    		sum += now ;
    		v[++fim] = {i, a[i]} ;
    	}
    	
    	return sum ; 
     
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
     
    	cin >> n ; 
     
    	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    	ans += calc() ;
        for(int i = 1 ; i <= n ; i++) a[i] = -a[i] ;
        ans += calc() ;
        cout << ans << "\n" ; 
     
    } 

    #include<bits/stdc++.h>
    #define pb push_back 
     
    using namespace std ;
     
    const int maxn = 2e6 + 12 ; 
     
    int n, v[2][maxn], dpmax[maxn][2], dpmin[maxn][2] ;
     
    int mind(int n, int flag){
     
    	if(n == 0) return 0 ; 
    	if(dpmin[n][flag] != -1) return dpmin[n][flag] ;
     
    	int ans = 4*maxn ; 
     
    	for(int i = 0 ; i < 2 ; i++){
    		if(v[i][n] <= v[flag][n+1]) ans = min(ans, mind(n-1, i) + i) ; 
    	}
     
    	return dpmin[n][flag] = ans ; 
     
    }
     
    int maxd(int n, int flag){
     
    	if(n == 0) return 0 ; 
    	if(dpmax[n][flag] != -1) return dpmax[n][flag] ;
     
    	int ans = -4*maxn ; 
     
    	for(int i = 0 ; i < 2 ; i++){
    		if(v[i][n] <= v[flag][n+1]) ans = max(ans, maxd(n-1, i) + i) ; 
    	}
     
    	return dpmax[n][flag] = ans ; 
     
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n ; 
     
    	n*=2 ; 
    	string s ;
     
    	for(int i = 1 ; i <= n ; i++) cin >> v[0][i] ;
    	for(int i = 1 ; i <= n ; i++) cin >> v[1][i] ;
     
    	v[1][n+1] = v[0][n+1] = (int) 2e9 ; 
    	int qa = n/2, qb = n/2, ant = 0 ;
        memset(dpmin, -1, sizeof dpmin), memset(dpmax, -1, sizeof dpmax) ; 
     
        for(int i = n ; i > 0 ; i--){
     
        	if(mind(i, ant) <= qb && maxd(i, ant) >= qb){
     
        		int mina = mind(i - 1, 0), maxa = maxd(i-1, 0) ;
        		int minb = mind(i-1, 1), maxb = maxd(i-1, 1) ; 
     
        		if(qa && mina <= qb && maxa >= qb && v[0][i] <= v[ant][i+1]) qa--, s.pb('A'), ant = 0 ;
        		else if(qb) qb--, ant = 1, s.pb('B') ; 
     
        	}
     
        	else{
        		cout << -1 << "\n" ;
        		return 0 ; 
        	}
     
        }
     
        reverse(s.begin(), s.end()) ;
     
        if(qa != 0 || qb != 0) cout << -1 << "\n" ;
        else cout << s << "\n" ;
     
    } 

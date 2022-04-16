    #include<bits/stdc++.h>
    #define int long long
    using namespace std ; 
     
    // cada circulo é um nó 
    // aresta entre tds q se cruzam 
    // conta qts componentes cruzam com cada 
    // lado da rua pois essas precisamos passar 
     
    const int maxn = 1e3 + 5 ;
     
    int t, n, X, Y, sz[maxn], vis[maxn] ; 
    int pai[maxn], mnx[maxn], mny[maxn], mxx[maxn], mxy[maxn] ; 
     
    struct circ{
     
    	int x, y, mn_x, mn_y, mx_x, mx_y, r ; 
     
    } ; 
     
    circ v[maxn] ; 
     
    struct DSU{
     
    	int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }
     
    	void join(int a, int b){
    		a =  find(a), b = find(b) ; 
    		if(sz[a] > sz[b]) swap(a, b) ; // liga a p b 
    		mnx[b] = min(mnx[b], mnx[a]), mny[b] = min(mny[a], mny[b]) ; 
    		mxx[b] = max(mxx[b], mxx[a]), mxy[b] = max(mxy[b], mxy[a]) ; 
    		pai[a] = b ; 
    		sz[b] += sz[a] ; 
    	}
     
    } dsu ; 
     
    bool touch(circ a, circ b){
     
    	int d = (abs(a.x - b.x)*abs(a.x - b.x)) + (abs(a.y - b.y)*abs(a.y - b.y)) ; 
    	return d <= (a.r + b.r)*(a.r + b.r) ; 
     
    }
     
    bool touch_side(int a){
     
    	if(mnx[a] <= 0 && mxx[a] >= X) return 1 ;  
    	if(mny[a] <= 0 && mxy[a] >= Y) return 1 ; 
     
    	return 0 ; 
     
    }
     
    int32_t main(){
     
    	cin >> t ; 
     
    	while(t--){
     
    		cin >> n >> X >> Y ; 
     
    		for(int i = 1 ; i <= n ; i++){
    			int X, Y, R ; 
    			cin >> X >> Y >> R ;
    			v[i].mn_x = X - R ; v[i].mx_x = X + R ;
    			v[i].mn_y = Y - R ; v[i].mx_y = Y + R ; 
    			v[i].r = R ; v[i].x = X, v[i].y = Y ; 
    		} 
     
    		for(int i = 1 ; i <= n ; i++){
    			pai[i] = i ; sz[i] = 1 ; 
    			mnx[i] = v[i].mn_x, mxx[i] = v[i].mx_x ;
    			mny[i] = v[i].mn_y, mxy[i] = v[i].mx_y ; 
     
    		}   
     
    		for(int i = 1 ; i <= n ; i++){
    			for(int j = i+1 ; j <= n ; j++){
    				if(touch(v[i], v[j])){
    					dsu.join(i, j) ; 
    					// cout << i << " " << j << "\n" ;
    				} 
    			}
    		}
     
    		// for(int i = 1 ; i <= n ; i++){
    		// 	cout << pai[i] << " " << mnx[i] << " " << mxx[i] << " " << mny[i] << " " << mxy[i] << "\n" ; 
    		// }
     
    		int ct = 0 ; 
     
    		memset(vis, 0, sizeof vis) ; 
     
    		for(int i = 1 ; i <= n ; i++){
    			if(vis[dsu.find(i)]) continue ;
    			vis[dsu.find(i)] = 1 ; 
    			if(touch_side(dsu.find(i))) ct++ ;  
    		}
     
    		cout << ct << "\n" ; 
     
    	}
     
    }

    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    const int maxn = 10005 ; 
     
    int t, n, u, q, l, r, val ; 
    int bit[maxn] ; 
     
    struct BIT{
     
    	void upd(int pos, int val){
    		for(; pos < maxn ; pos += pos&-pos) bit[pos] += val ; 
    	}
     
        int query(int pos){
        	int tot = 0 ; 
        	for(; pos > 0 ; pos -= pos&-pos) tot += bit[pos] ; 
        	return tot ; 
        }
     
    } Bit ; 
     
    int32_t main(){
     
    	cin >> t ; 
     
    	while(t--){
    		
    		for(int i = 0 ; i < maxn ; i++) bit[i] = 0 ; 
     
    		cin >> n >> u ; 
     
    		for(int i = 1 ; i <= u ; i++){
    			cin >> l >> r >> val ; 
    			l++, r++ ; 
    			Bit.upd(l, val), Bit.upd(r+1, -val) ; 
    		}
     
    		cin >> q ; 
     
    		for(int i = 1, pos ; i <= q ; i++){
    			cin >> pos ; 
    			pos++ ; 
    			cout << Bit.query(pos) << "\n" ; 
    		}
     
    	}
     
    } 

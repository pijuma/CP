    #include<bits/stdc++.h>
    #define int long long
    using namespace std ;
     
    const int inf = 1e9 + 1 ;
    const int maxn = 1e3 + 5 ;
     
    int v[maxn], n, dp[maxn] ;
    map<int,int> bit ;
     
    struct BIT{
     
        void upd(int pos, int val){
            if(pos <= 0) return ;
            for(; pos < 4*inf ; pos += pos&-pos) bit[pos] = max(bit[pos], val) ;
        }
     
        int query(int pos){
            if(pos <= 0) return 0 ;
            int tot = 0 ;
            for(; pos > 0 ; pos -= pos&-pos) tot = max(tot, bit[pos]) ;
            return tot ;
        }
     
    } Bit ;
     
    int32_t main(){
     
        ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
     
        cin >> n ;
     
        for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
     
        for(int i = 1 ; i <= n ; i++) v[i] += inf  ;
     
        int val = 0 ;
     
        for(int i = 1 ; i <= n ; i++){
            int mx = Bit.query(v[i] - 1) ;
            Bit.upd(v[i], mx + 1) ;
            dp[i] = mx + 1 ;
            val = max(val, v[i]) ;
        }
     
        int p = 0 ;
        int ans = Bit.query(val+1) ;
     
        for(int i = 1 ; i <= n ; i++) if(dp[i] == ans) p = i ;
     
        vector<int> lis ;
     
        while(p){
            lis.push_back(v[p]) ;
            int j = p-1 ;
            for(; j > 0 ; j--){
                    if(dp[j] == dp[p] - 1 &&  v[p] >= v[j]) break ;
            }
            p = j ;
        }
     
        reverse(lis.begin(), lis.end()) ;
     
        cout << lis.size() << "\n" ;
        for(auto a : lis) cout << a - inf << " " ;
        cout << "\n" ;
     
    }

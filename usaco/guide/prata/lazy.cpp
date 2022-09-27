#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 405 ;

int n, k, m[maxn][maxn], ps[maxn][maxn] ;

int32_t main(){

    ifstream cin("lazy.in");
    ofstream cout("lazy.out");

    cin >> n >> k ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> m[i][j] ;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){ //psum of each row
            ps[i][j] = ps[i][j-1] + m[i][j] ;
        }
    }

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){ // testar i, j como inicio
            int t = k ;
            int sum = 0 ;
            for(int row_ct = 0 ; row_ct <= k ; row_ct++){
                int beg = j - t, endd = j + t ;
                //cout << i-row_ct << " " << i+row_ct << " " << beg << " " << endd << "\n" ;
                beg = max(1LL, beg), endd = min(n, endd) ;
                if(i+row_ct <= n && row_ct) sum += ps[i+row_ct][endd] - ps[i+row_ct][beg-1] ;
                if(i - row_ct >= 1) sum += ps[i-row_ct][endd] - ps[i-row_ct][beg-1] ;
                t-- ;
            }
            ans = max(ans, sum) ;
        }
    }

    cout << ans << "\n" ;

}

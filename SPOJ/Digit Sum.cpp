#include<bits/stdc++.h>
#define int long long
 
using namespace std ;
 
const int maxn = 17 ;
int t ;
long long a, b ;
long long dps[maxn][2], dp[maxn][2] ;
vector<int> num ;
 
    int solved(int d, bool flag){
        if(d == num.size()) return 1 ;
        if(dp[d][flag] != -1) return dp[d][flag] ;
        int tot = 0 ;
        if(flag){
            for(int i = 0 ; i < 10 ; i++) tot += solved(d+1, flag) ;
        }
        else{
            for(int i = 0 ; i < num[d] ; i++) tot += solved(d+1, !flag) ;
            tot += solved(d+1, flag) ;
        }
        return dp[d][flag] = tot ;
    }
 
    int solven(int d, bool flag){
        if(d == num.size()) return 0 ;
        if(dps[d][flag] != -1) return dps[d][flag] ;
        int soma = 0 ;
        if(flag){ // safe
            for(int i = 0 ; i < 10 ; i++){
                soma += i*solved(d+1, flag) + solven(d+1, flag) ;
            }
        }
        else{
 
            for(int i = 0 ; i < num[d] ; i++){
                soma += i*solved(d+1, !flag) + solven(d+1, !flag) ;
            }
            soma += num[d]*solved(d+1, flag) + solven(d+1, flag) ;
        }
        return dps[d][flag] = soma ;
 
    }
 
    int create(long long x){
 
        if(x <= 0) return 0 ;
        num.clear() ;
        while(x){
            num.push_back(x%10) ;
            x/=10 ;
        }
        reverse(num.begin(), num.end()) ;
        memset(dps, -1, sizeof dps) ;
        memset(dp, -1, sizeof dp) ;
        return solven(0, 0) ;
 
    }
 
int32_t main(){
 
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
 
    cin >> t ;
    while(t--){
        cin >> a >> b ;
        cout << create(b) - create(a-1) << "\n" ;
    }
}

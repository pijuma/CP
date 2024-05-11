#include<bits/stdc++.h>
using namespace std ; 

/*

*/

const int maxn = 110 ; 
const int maxx = 1e4 + 5 ; 

int k ; 
int s[maxn], dp[maxx] ; 
int freq[maxx] ;

int find_mex(vector<int> &a){
    if(a.size() == 0) return 0 ;
    int mex = 0 ; 
    for(auto b : a) freq[b]++ ; 
    while(freq[mex]) mex++ ; 
    for(auto b : a) freq[b]-- ; 
    return mex ; 
}

int solve_dp(int val){
    if(val == 0) return 0; 
    if(dp[val] != -1) return dp[val] ; 
    //todos os filhos
    vector<int> fi ; 
    for(int i = 1 ; i <= k ; i++){
        if(val >= s[i]) fi.push_back(solve_dp(val-s[i])) ; 
    }
    return dp[val] = find_mex(fi) ; 
}

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> k ; 

    for(int i = 1 ; i <= k ; i++) cin >> s[i] ;  

    memset(dp, -1, sizeof(dp)) ; 

    for(int i = 0 ; i < maxx ; i++) solve_dp(i) ; 

    int q ; cin >> q ; 

    while(q--){
        int m ; cin >> m ;
        int xorr = 0 ;
        for(int i = 1 ; i <= m ; i++){
            int a ; cin >> a ;  
            xorr ^= dp[a] ; 
            //cout <<  solve_dp(a) << "\n" ; 
        }
        if(xorr) cout << 'W' ; 
        else cout << 'L' ; 
    }

    cout << "\n" ; 

}

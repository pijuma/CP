#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<ll, ll>
using namespace std ;
 
const int maxn = 2e5 + 5 ;
const ll inf =  9e18 ;
 
bool isleft[maxn] ;
pii p[maxn] ;
 
bool cmp(int a, int b){return p[a].first < p[b].first ; }
bool cmp2(int a, int b){return p[a].second < p[b].second ; }
 
ll square(ll dx){ return dx*dx ; }
ll dist(pii A, pii B){
    ll dx = A.first-B.first;
    ll dy = A.second-B.second;
    return square(dx) + square(dy);
}
 
ll brute(vector<ll> px){
 
    ll mn = inf ;
 
    for(int i = 0 ; i < (int) px.size() ; i++){
        for(int j = i ; j < (int) px.size() ; j++){
            if(i == j) continue ;
            mn = min(mn, dist(p[px[i]], p[px[j]])) ;
        }
    }
 
    return mn ;
 
}
 
ll solve(vector<ll> vx, vector<ll> vy){
 
    if((int) vx.size() <= 4) return brute(vx) ;
 
    vector<ll> vex, vdx, vey, vdy ;
 
    ll mid = vx.size()/2 ;
    ll midval = p[vx[mid]].first ;
 
    for(int i = 0 ; i < (int) vx.size() ; i++){
        if(i < mid){
            vex.push_back(vx[i]) ;
            isleft[vx[i]] = 1 ;
        }
        else{
          vdx.push_back(vx[i]) ;
          isleft[vx[i]] = 0 ;
        }
    }
 
    for(int i = 0 ; i < (int) vy.size() ; i++){
        if(isleft[vy[i]]) vey.push_back(vy[i]) ;
        else vdy.push_back(vy[i]) ;
    }
 
    ll mn1 = solve(vex, vey), mn2 = solve(vdx, vdy) ;
    ll d = min(mn1, mn2) ;
 
    vector<ll> une ;
 
    for(int i = 0 ; i < (int) vy.size() ; i++){
        if(square(p[vy[i]].first - midval) < d) une.push_back(vy[i]) ;
    }
 
    for(int i = 0 ; i < une.size() ; i++){
        for(int j = i ; j < (int) une.size() && square(p[une[i]].second - p[une[j]].second) < d ; j++){
            if(i == j) continue ;
            d = min(d, dist(p[une[i]], p[une[j]])) ;
        }
    }
 
    return d ;
 
}
 
int32_t main(){
 
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
 
    int n ;
 
    cin >> n ;
 
    vector<int> px, py ;
 
    for(int i = 0, a, b ; i < n ; i++){
        cin >> a >> b ;
        p[i] = {a, b} ;
        px.push_back(i) ;
        py.push_back(i) ;
    }
 
    sort(px.begin(), px.end(), cmp) ;
    sort(py.begin(), py.end(), cmp2) ;
 
    cout << solve(px, py) << "\n" ;
 
}

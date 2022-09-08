//https://oj.uz/problem/view/LMIO19_noras
#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 2e5 + 5 ;

int n, r, xi[maxn], xf[maxn], yi[maxn], yf[maxn] ;
vector<pair<int,int>> inter ;

bool test(int a, int b, int c, int x){ return (a*x*x + b*x + c <= 0) ; }

pair<int,int> bsk(double a, double b, double c){
    double d = (b*b) - (4*a*c) ;
    if(d < 0) return {1, 0} ;
    double k = (-b - sqrt(d))*1.00/(2*a*1.00) ;
    double k2 = (-b + sqrt(d))*1.00/(2*a*1.00) ;
    if(k < 0 && k2 < 0) return {1, 0} ;
    if(k < 0) k = 0LL ;
    if(k2 < 0) k2 = 0LL ;
    //cout << a << " " << b << " " << c << " " << d << " " << k2 << "\n" ;
    return {k, k2} ;
}


int32_t main(){

    cin >> n >> r ;

    for(int i = 1 ; i <= n ; i++) cin >> xi[i] >> yi[i] >> xf[i] >> yf[i] ;

    for(int i = 1 ; i <= n ; i++){
        int dx = (xf[i]-xi[i]), dy = (yf[i]-yi[i]) ;
        int a = ((dx*dx)+(dy*dy)) ;
        int b = (2*xi[i]*dx) + (2*yi[i]*dy) ;
        int c = (xi[i]*xi[i]) + (yi[i]*yi[i]) - (r*r) ;
        //cout << a << " " << b << " " << c << "\n" ;
        pair<int,int> x = bsk(a, b, c) ;
        int r1 = x.first, r2 = x.second ;
        bool ok = 0 ;
        for(int j = max(0LL, r1 - 2) ; j <= r1 + 2 ; j++){
            int px = xi[i] + (dx*j) ;
            int py = yi[i] + (dy*j) ;
            if((px*px) + (py*py) <= r*r){
                ok = 1 ; r1 = j ; break ;
            }
        }
        for(int j = r2 + 2 ; j >= max(0LL, r2-2) ; j--){
            int px = xi[i] + (dx*j), py = yi[i] + (dy*j) ;
            if((px*px) + (py*py) <= r*r){
                ok = 1 ;
                r2 = j ; break ;
            }
        }
        if(!ok) continue ;
        inter.push_back({r1, 0}) ; inter.push_back({r2, 1}) ;
    }

    int ans = 0, sm = 0 ;

    sort(inter.begin(), inter.end()) ;

    //for(auto a : inter) cout << a.first << " " << a.second << "\n" ;

    for(auto a : inter){
        if(a.second) sm-- ;
        else sm++ ;
        ans = max(ans, sm) ;
    }

    cout << ans << "\n" ;

}

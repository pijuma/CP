// https://dmoj.ca/problem/dmpg15g6
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 2e5 + 5 ;

int n, m, v[maxn], q, a[maxn] ;
vector<int> freq[maxn] ;

int main(){
    
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    
    srand(time(0)) ;

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        freq[a[i]].push_back(i) ;
    }

    cin >> q ;

    while(q--){
        int l, r ; cin >> l >> r ;
        int ct = 50, sec = 0, ant = 0 ;
        while(ct--){
            int vv = (l + (rand())%(r-l+1)) ;
            int qtd = upper_bound(freq[a[vv]].begin(), freq[a[vv]].end(), r) - lower_bound(freq[a[vv]].begin(), freq[a[vv]].end(), l) ;
            if(qtd*3 >= 2*(r-l+1)){
                sec = 2 ;
                cout << "YES\n" ; break ;
            }
            else if(qtd*3 >= (r-l+1)){
                if(!sec) sec = 1, ant = a[vv] ;
                else if(a[vv] != ant){
                    sec = 2 ;
                    cout << "YES\n" ; break ;
                }
            }
        }
   	    if(sec != 2) cout << "NO\n" ;
    }

}

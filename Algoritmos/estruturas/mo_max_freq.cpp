/*
m peças posicionadas p preencher a linha 
n espaços 
peça a esq e peça a dir 
*/

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 3e5 + 5 ; 

#define pb push_back
#define pii pair<int,int> 
#define f first 
#define s second 

int n, m, k, q, freq[maxn]; 
int v[maxn], resp[maxn], f_freq[maxn] ;
int sq, ans, mx_freq ; 

set<int> kras ; 
struct S{
    int l, r, id ; 
} ;
 
S qr[maxn] ; 

bool cmp(S a, S b){
    if((a.l/sq) != (b.l/sq)) return a.l < b.l ; 
    return (((a.l/sq)&1) ? (a.r < b.r) : (a.r > b.r)) ; 
}

void add(int id){
    if(f_freq[freq[v[id]]]) f_freq[freq[v[id]]]-- ; 
    freq[v[id]]++ ;
    f_freq[freq[v[id]]]++ ; 
    mx_freq = max(mx_freq, freq[v[id]]) ;  
}

void remove(int id){
    f_freq[freq[v[id]]]-- ; 
    freq[v[id]]-- ; 
    if(freq[v[id]]){
        f_freq[freq[v[id]]]++ ; 
    }
    while(mx_freq >= 1 && f_freq[mx_freq]==0) mx_freq-- ; 
}

void solve(){

    sq = 600 ; 

    cin >> n >> q ; 

    for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

    for(int i = 1 ; i <= q ; i++){
        int l, r ; cin >> l >> r ; 
        qr[i] = {l, r, i} ; 
    }

    sort(qr + 1, qr + 1 + q, cmp) ; 

    int ini = 1, fim = 0 ;

    for(int i = 1 ; i <= q ; i++){
        
        int L = qr[i].l, R = qr[i].r ; 

        //cout << L << " " << R << "\n" ; 

        while(ini > L) add(--ini) ; 
        while(ini < L) remove(ini++) ;  
        while(fim < R) add(++fim) ; 
        while(fim > R) remove(fim--) ; 

        int sz = R-L+1 ; 
        int ans = R-L+1 ; 

        if(mx_freq <= ceil(sz/2)) ans = 1 ;
        else ans = (2*mx_freq) - sz  ; 
        resp[qr[i].id] = ans ; 
        // se o max freq no meu intervalo 
        // tem freq < n/2 ent a resp eh 1 
        // se n eu agrupo kras n +freqs+1 com o mx freq e somo sozinho oq precisar dps
        //cout << mx_freq << "\n" ; 

    }

    for(int i = 1 ; i <= q ; i++) cout << resp[i] << "\n" ; 

}

int main(){ 

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    int t = 1 ; // cin >> t ; 

    while(t--) solve() ; 

}

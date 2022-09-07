// https://codeforces.com/contest/319/problem/C
// motoserra com uma bateria q dura uma unidade
// qd vc corta uma arvore inteira i vc ganha bi
// preço p recarregar é o bj do maior j tal q vc cortou totalment a arvore j (j maior arvore em id q vc ja cortou)
// a cada unidade vc paga bj p recarregar
// b's são decrescentes
// qual o valor min q vc gasta p cortar a ultima arvore 1o (b dela é 0)
// smp mlr cortar mais a direita
// a seg retorna o menor valor
// dpi = min(dpj + hi*bj)
// dp[i] = query(hi) ; a = bi, b = dp[i] ; - hi eh o x
#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
using namespace std ;

const int maxn = 3e5 + 5 ;
const int inf = 2e9 + 5 ;

struct T{
    int a, b ;
};

int n, h[maxn], b[maxn], hh[maxn], h_back[maxn] ;
T tree[4*maxn] ;

struct SEG{

    int f(T k, int x){ return k.a*h_back[x] + k.b ; }

    void build(int no, int i, int j, T reta){
        tree[no] = reta ;
        if(i == j) return ;
        build(esq, i, meio, reta), build(dir, meio + 1, j, reta) ;
    }

    void add(int no, int i, int j, T reta){
        if(i == j){
            int att = f(tree[no], i), neww = f(reta, i) ;
            if(att > neww) tree[no] = reta ;
            return ;
        }
        int at_m = f(tree[no], meio), neww_m = f(reta, meio) ;
        if(at_m > neww_m) swap(reta, tree[no]) ;
        int at_i = f(tree[no], i), at_j = f(tree[no], j) ;
        int neww_i = f(reta, i), neww_j = f(reta, j) ;
        if(at_i > neww_i) add(esq, i, meio, reta) ;
        else if(at_j > neww_j) add(dir, meio + 1, j, reta) ;
    }

    int query(int no, int i, int j, int pos){
        if(i == j) return f(tree[no], pos) ;
        if(pos <= meio) return min(f(tree[no], pos), query(esq, i, meio , pos)) ;
        else return min(f(tree[no], pos), query(dir, meio + 1, j, pos)) ;
    }

} Seg ;

int32_t main(){

    cin >> n ;

    vector<int> vec ;

    T null ; null = {inf, inf} ;

    Seg.build(1, 1, n, null) ;

    for(int i = 1 ; i <= n ; i++){
        cin >> hh[i] ;
        vec.push_back(hh[i]) ;
    }

    for(int i = 1 ; i <= n ; i++) cin >> b[i] ;

    sort(vec.begin(), vec.end()) ;

    for(int i = 1 ; i <= n ; i++){
        h[i] = lower_bound(vec.begin(), vec.end(), hh[i]) - vec.begin() + 1 ;
        h_back[h[i]] = hh[i] ;
    }

    T ff ; ff = {b[1], 0} ;
    Seg.add(1, 1, n, ff) ;

    for(int i = 2 ; i <= n ; i++){
        int dpi = Seg.query(1, 1, n, h[i]) ;
        //cout << dpi << "\n" ;
        T k ; k = {b[i], dpi} ;
        Seg.add(1, 1, n, k) ;
    }

    cout << Seg.query(1, 1, n, h[n]) << "\n" ;

}

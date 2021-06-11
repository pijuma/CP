#include<bits/stdc++.h>
#define esq (2*no)
#define dir (2*no + 1)
#define meio ((i+j)>>1)

using namespace std ;

const int maxn = 1e5 + 1 ;
int n, resp, h[maxn], tree[4*maxn] ;

// seg guarda maximo no intervalo i, j

struct Seg{

    void built(int no, int i, int j){
        if(i==j){
            tree[no] = h[i] ;
            return ;
        }
        built(esq, i, meio) ;
        built(dir, meio+1, j) ;
        tree[no] = max(tree[esq], tree[dir]) ;
    }

    int query(int no, int i, int j, int a, int b){
        if(a > j || b < i) return 1 ;
        if(a <= i && j <= b) return tree[no] ;
        return max(query(esq, i, meio, a, b), query(dir, meio+1, j, a, b)) ;
    }

}seg;

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> h[i] ;
    seg.built(1, 1, n) ;
    for(int i = 1 ; i <= n ; i++){
        int lm = seg.query(1, 1, n , 1, i-1) ;
        int rm = seg.query(1, 1, n, i + 1, n) ;
        if(h[i] < lm && h[i] < rm) resp++ ;
    }
    cout << resp ;

}

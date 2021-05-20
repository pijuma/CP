//dado intervalo a b -> intervalo de maior soma
//e qtd de valores no intervalo

#include<bits/stdc++.h>
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
#define ll long long
#define _ ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
using namespace std ;

const int maxn = 1e5 + 3 ;

struct Tree{
    int sum, ans, pref, suf, ts, tp, ta, tsu ;
};

int v[maxn] ;
Tree tree[4*maxn] ;

struct Seg{

    Tree join(Tree a, Tree b){
        Tree r ;
        r.sum = a.sum + b.sum ;
        r.tsu = a.tsu + b.tsu ;
        if(a.pref > a.sum + b.pref) r.pref = a.pref, r.tp = a.tp ;
        else if(a.pref == a.sum + b.pref) r.pref = a.pref, r.tp = max(a.tp, a.tsu + b.tp) ;
        else r.pref = a.sum + b.pref, r.tp = a.tsu + b.tp ;
        if(b.suf > b.sum + a.suf) r.suf = b.suf, r.ts = b.ts ;
        else if(b.suf == b.sum + a.suf) r.suf = b.suf, r.ts = max(b.ts, b.tsu + a.ts) ;
        else r.suf = b.sum + a.suf, r.ts = b.tsu + a.ts ;
        // ans -> a.ans, b.ans, a.suf + b.pref + maior n° elem
        if(a.ans > b.ans && a.ans > a.suf + b.pref) r.ans = a.ans, r.ta = a.ta ;
        else if(b.ans > a.ans && b.ans > a.suf + b.pref) r.ans = b.ans, r.ta = b.ta ;
        else if(a.ans == b.ans && a.ans == a.suf + b.pref) r.ans = b.ans, r.ta = max(max(a.ta, b.ta), a.ts + b.tp) ;
        else r.ans = a.suf + b.pref, r.ta = a.ts + b.tp ;
        return r ;
    }

    Tree init(int v){
        Tree r ;
        r.sum = v ;
        r.ans = r.pref = r.suf = v ;
        if(v == -0x3f3f3f3f3f3f) r.tsu = r.ts = r.tp = r.ta = 0 ;
        else r.tsu = r.ts = r.tp = r.ta = 1 ;
        return r ;
    }

    void build(int no, int i, int j){
        if(i == j){
            tree[no] = init(v[i]) ;
            return ;
        }
        build(esq, i, meio), build(dir, meio + 1, j) ;
        tree[no] = join(tree[esq], tree[dir]) ;
        return ;
    }

    void see(int n){
        for(int i = 1 ; i <= 4*n ; i++) cout << i << " " << tree[i].ans << endl ;
        return ;
    }

    Tree query(int no, int i, int j, int a, int b){
        if(a <= i && b >= j) return tree[no] ;
        if( b <= meio ) return query( esq, i , meio , a , b ) ;
        if( a > meio ) return query( dir , meio+1, j , a , b) ;
        return join(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ;
    }

}seg;

int main(){
    _
    int t, n, q ;
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
        seg.build(1, 1, n) ;
        //seg.see(n) ;
        cin >> q ;
        for(int i = 1 ; i <= q ; i++){
            int a, b ;
            cin >> a >> b ;
            Tree resp = seg.query(1, 1, n, a, b) ;
            //cout << "query " << i << " resp:\n" ;
            cout << resp.ans << " " << resp.ta << "\n" ;
        }
    }

}

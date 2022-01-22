    #include<bits/stdc++.h>
    #define esq (2*no)
    #define dir ((2*no)+1)
    #define meio ((i+j)>>1)
     
    // seg vai ser uma struct
    // e vai guardar o valor minimo
    // e a qtd de valores minimos no trecho
    // se o min das duas forem iguais
    // n�s somamos
    // se nn pegamos o menor e colocamos o valor como sendo esse
     
    using namespace std ;
     
    const int maxn = 1e5 + 4 ;
     
    struct Tree{
        int mn, qtdmn ;
    };
     
    Tree tree[4*maxn] ;
    int v[maxn], n, m, a, b, c ;
     
    struct SEG{
     
        Tree join(Tree a, Tree b){
            Tree c ;
            if(a.mn > b.mn) swap(a,b) ;
            if(a.mn == b.mn) c = {a.mn, a.qtdmn + b.qtdmn} ;
            else c = {a.mn, a.qtdmn} ;
            return c ;
        }
     
        void built(int no, int i, int j){
            if(i == j){
                tree[no] = {v[i], 1} ;
                return ;
            }
            built(esq, i, meio) ;
            built(dir, meio+1, j) ;
            tree[no] = join(tree[esq], tree[dir]) ;
        }
     
        void att(int no, int i, int j, int pos, int val){
            if(i==j){
                tree[no] = {val, 1} ;
                v[i] =val ;
                return ;
            }
            if(pos <= meio) att(esq, i, meio, pos, val) ;
            else att(dir, meio+1, j, pos, val) ;
            tree[no] = join(tree[esq], tree[dir]) ;
        }
     
        Tree query(int no, int i, int j, int a, int b){
            if(a > j || b < i) return {(0x3f3f3f3f), 1} ;
            if(i >= a && j <= b) return tree[no] ;
            return join(query(esq, i, meio, a, b), query(dir, meio+1, j, a, b)) ;
        }
     
    }seg;
     
    int main(){
     
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     
        cin >> n >> m ;
        for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
        seg.built(1, 1, n) ;
        for(int i = 1 ; i <= m ; i++){
            cin >> a >> b >> c ;
            b++ ;
            if(a == 1) seg.att(1, 1, n, b, c) ;
            else{
                Tree ans = seg.query(1, 1, n, b, c) ;
                cout << ans.mn << " " << ans.qtdmn << "\n" ;
            }
        }
    }

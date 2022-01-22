    #include<bits/stdc++.h>
    #define esq (2*no)
    #define dir ((2*no)+1)
    #define meio ((i+j)>>1)
     
    using namespace std ;
     
    const int maxn = 1e5 + 3 ;
    const long long inf = 1e13 + 4 ;
     
    long long n, m, a, b, c, tree[4*maxn], v[maxn] ;
     
    struct Seg{
     
        void built(int no, int i, int j){
            if(i==j){
                tree[no] = v[i] ;
                return ;
            }
            built(esq, i, meio) ;
            built(dir, meio+1, j) ;
            tree[no] = min(tree[esq], tree[dir]) ;
        }
     
        void att(int no, int i, int j, int pos, int val){
            if(i==j){
                tree[no] = val ;
                v[i] = val ;
                return ;
            }
            if(pos <= meio) att(esq, i, meio, pos, val) ;
            else att(dir, meio+1, j, pos, val) ;
            tree[no] = min(tree[esq], tree[dir]) ;
        }
     
        long long query(int no, int i, int j, int a, int b){
            if(a <= i && j <= b) return tree[no] ;
            if(a > j || b < i) return inf ;
            return min(query(esq, i, meio, a, b), query(dir, meio+1, j, a, b)) ;
        }
     
    }seg;
     
    int main(){
     
        cin >> n >> m ;
        for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
        seg.built(1, 1, n) ;
        for(int i = 1 ; i <= m ; i++){
            cin >> a >> b >> c ;
            b++ ;
            if(a == 1) seg.att(1, 1, n, b, c) ;
            else cout << seg.query(1, 1, n, b, c) << "\n" ;
        }
    }

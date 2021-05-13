#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define esq (2*no)
#define meio ((i+j)>>1)
#define dir ((2*no)+1)
 
const int maxn = 2e5 + 5 ;
 
int n, q, tree[4*maxn], lazy[4*maxn], l, r, pos, v, x[maxn] ;
 
struct SEG{
  
    void flush(int no, int i, int j){
       if(!lazy[no]) return ;
       tree[no] += (j-i+1)*lazy[no] ;
       if(i!=j){
        lazy[esq] += lazy[no] ;
        lazy[dir] += lazy[no] ;
       }
       lazy[no] = 0 ;
    }
  
    void build(int no, int i, int j){
        if(i == j){
            lazy[no] = 0 ;
            tree[no] = x[i] ;
            return ;
        }
        build(esq, i, meio), build(dir, meio + 1, j) ;
        tree[no] = tree[esq]+tree[dir] ;
    }
  
   void att(int no, int i, int j, int a, int b, int v){
       flush(no, i, j) ;
        if(a > j || b < i) return  ;
        if(a <= i && b >= j){
            lazy[no] = v ;
            flush(no, i, j) ;
            return ;
        }
        att(esq, i, meio, a, b, v), att(dir, meio + 1, j, a, b, v) ;
        tree[no] = tree[esq]+tree[dir] ;
    }
  
    int query(int no, int i, int j, int a, int b){
        flush(no, i, j) ;
        if(a > j || b < i) return 0 ;
        if(a <= i && b >= j) return tree[no] ;
        return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ;
    }
  
} seg;

int32_t main(){
 
    cin >> n >> q ;
 
    for(int i = 1 ; i <= n ; i++) cin >> x[i] ;
  
    seg.build(1, 1, n) ;
  
    while(q--){
      
        int t ;
        cin >> t ;
      
        if(t == 1){
            cin >> l >> r >> v ;
            seg.att(1, 1, n, l, r, v) ;
        }
      
        else{
            cin >> l ;
            cout << seg.query(1, 1, n, l, l) << "\n" ;
        }
      
    }
  
}

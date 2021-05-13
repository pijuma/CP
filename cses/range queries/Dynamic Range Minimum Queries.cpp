#include<bits/stdc++.h>
using namespace std ;
 
#define esq (2*no)
#define meio ((i+j)>>1)
#define dir ((2*no)+1)
 
const int maxn = 2e5 + 5 ;
 
int n, q, tree[4*maxn], l, r, pos, v, x[maxn] ;
 
struct SEG{
  
    void build(int no, int i, int j){
        if(i == j){
            tree[no] = x[i] ;
            return ;
        }
        build(esq, i, meio), build(dir, meio + 1, j) ;
        tree[no] = min(tree[esq], tree[dir]) ;
    }
  
    void att(int no, int i, int j, int posi, int val){
        if(i == j && posi == i){
            tree[no] = val, x[i] = val ;
            return  ;
        }
        if(posi <= meio) att(esq, i, meio, posi, val) ;
        else att(dir, meio + 1, j, posi, val) ;
        tree[no] = min(tree[esq], tree[dir]) ;
    }
  
    int query(int no, int i, int j, int a, int b){
        if(a > j || b < i) return 0x3f3f3f3f3f ;
        if(a <= i && b >= j) return tree[no] ;
        return min(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ;
    }
  
} seg;

int main(){
 
    cin >> n >> q ;
 
    for(int i = 1 ; i <= n ; i++) cin >> x[i] ;
  
    seg.build(1, 1, n) ;
  
    while(q--){
      
        int t ;
        cin >> t ;
      
        if(t == 1){
            cin >> pos >> v ;
            seg.att(1, 1, n, pos, v) ;
        }
      
        else{
            cin >> l >> r ;
            cout << seg.query(1, 1, n, l, r) << "\n" ;
        }
      
    }
  
}

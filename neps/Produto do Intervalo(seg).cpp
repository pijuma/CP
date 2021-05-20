#include<bits/stdc++.h>
#define esq (2*no)
#define dir (2*no + 1)
#define meio ((i+j)>>1)

using namespace std ;

const int maxn = 1e5 + 3 ;

int n, k, x, valor, m ;
int tree[4*maxn], v[maxn] ;
char t ;
string ans ;
struct Seg{

    void built(int no, int i, int j){
        if(i == j){
            tree[no] = v[i] ;
            return ;
        }
        built(esq, i, meio);
        built(dir, meio + 1, j) ;
        tree[no] = tree[esq]*tree[dir] ;
    }

    void att(int no, int i, int j, int pos, int val){
        if(i == j){
            tree[no] = val ;
            v[i] = val ;
            return ;
        }
        if(pos <= meio) att(esq, i, meio, pos, val) ;
        else att(dir, meio+1, j, pos, val) ;
        tree[no] = tree[esq]*tree[dir] ;
    }

    int query(int no, int i, int j, int a, int b){
        if(i >= a && j <= b){
            return tree[no] ;
        }
        if(b < i || a > j) return 1 ;
        return query(esq, i, meio, a, b)*query(dir, meio+1, j, a, b) ;
    }

}seg;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    while(cin >> n >> k){
        for(int i = 1 ; i <= n ; i++){
            cin >> v[i] ;
            if(v[i] > 0) v[i] = 1 ;
            if(v[i] < 0) v[i] = -1 ;
        }
        seg.built(1, 1, n) ;
        //for(int i = 1 ; i <= 4*n ; i++) cout << i << " "<< tree[i] << "\n" ;
        for(int i = 1 ; i <= k ; i++){
            // c = mudanca
            // p = mult
            cin >> t >> x >> valor ;
            if(t == 'C') {
                if(valor > 0) valor = 1 ;
                if(valor < 0) valor = -1 ;
                seg.att(1, 1, n, x, valor) ;
            }
            else{
                m = seg.query(1, 1, n, x, valor) ;
                //cout << v << "\n" ;
                if(m == 0) ans.push_back('0') ;
                else if(m < 0) ans.push_back('-') ;
                else ans.push_back('+') ;
            }
            //for(int i = 1 ; i <= 4*n ; i++) cout << i << " "<< tree[i] << "\n" ;
        }
        cout << ans << "\n";
        ans = "" ;
    }
}

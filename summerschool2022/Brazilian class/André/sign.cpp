
// i&1 || !i&1-> soma normal = +v e a soma invertida = -v 
// smp que une impar-impar soma normal = soma normal do 1o + soma invertida do 2o 
// soma invertida = soma invertida do 1o + normal do 2o 
// se une dois pares: 
// soma normal = soma normal 1a + soma normal da 2a 
// soma invertida = soma invertida da 1a + soma invertida da 2a 
// tam = tam 1a + tam 2o

#include<bits/stdc++.h>

#define ll long long 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m ; 
ll a[maxn] ; 

struct Tree{

    ll sn, si, tam ;

    Tree (ll sn = 0, ll si = 0, ll tam = 0) : sn(sn), si(si), tam(tam) {}

    Tree operator + (Tree a) const { return Tree((sn + a.sn), (si + a.si), (tam + a.tam)) ; }

    // soma normal, invertida, e tamanho 

} ;

Tree tree[4*maxn], null ; 

Tree join(Tree a, Tree b){

    Tree ans ; 

    ans.tam = a.tam + b.tam ; 

    if(!(a.tam&1) && !(b.tam&1)) ans.sn = a.sn + b.sn, ans.si = a.si + b.si ; //2 pares
    else if(!(a.tam&1) && (b.tam&1)) ans.sn = a.sn + b.sn, ans.si = a.si + b.si ; //1o par 2o impar 
    else if((a.tam&1) && !(b.tam&1)) ans.sn = a.sn + b.si, ans.si = a.si + b.sn ; // 1o impar 2o par 
    else ans.sn = a.sn + b.si, ans.si = a.si + b.sn ; //ambos impares

    return ans ; 

}

struct Seg{

    void build(int no, int i, int j){

        if(i == j){
            tree[no].tam = 1, tree[no].sn = a[i], tree[no].si = -a[i] ;
            return ; 
        }

        build(esq, i, meio), build(dir, meio + 1, j) ; 

        tree[no] = join(tree[esq], tree[dir]) ;

    }

    void att(int no, int i, int j, int pos, int v){

        if(i == j){
            tree[no].tam = 1, tree[no].sn = v, tree[no].si = -v ;
            a[i] = v ; 
            return ;
        }

        if(pos <= meio) att(esq, i, meio, pos, v) ; 
        else att(dir, meio + 1, j, pos, v) ; 

        tree[no] = join(tree[esq], tree[dir]) ;

    }

    Tree query(int no, int i, int j, int a, int b){

        Tree ans ; 

        if(a > j || b < i) return null ; 

        if(a <= i && b >= j) return tree[no] ; 

        ans = join(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ; 
        return ans ; 

    }

    void see(){
        for(int i = 1 ; i < 4*n ; i++) cout << i << " " << tree[i].sn << " " << tree[i].si << " " << tree[i].tam << "\n" ; 
    }

}seg ;

int main(){

    cin >> n ; 

    for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 

    seg.build(1, 1, n) ; 
    //seg.see() ;

    cin >> m ; 

    for(int i = 1, t ; i <= m ; i++){

        cin >> t ; 

        if(t == 1){
            int l, r ; 
            cin >> l >> r ; 
            Tree ans = seg.query(1, 1, n, l, r) ; 
            cout << ans.sn << "\n" ; 
        }

        else{
            int i, v ; 
            cin >> i >> v ; 
            seg.att(1, 1, n, i, v) ; 
        }
    }
}

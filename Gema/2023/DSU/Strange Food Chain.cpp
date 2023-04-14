// 3 versões de cada vertice -> ele, quem ele come e por quem eh comido 
#include<bits/stdc++.h>
using namespace std ; 

// ele -> i, quem ele come -> i + n, por quem ele eh comido -> i + 2*n
// a same b -> i - j, quem_ele_come(i) - quem_ele_come(j), por_quem_ele_eh_comido(i) - por_quem_ele_eh_comido(j)
// a mata b -> quem_ele_come(a) - b, por_quem_ele_eh_comido(b) - a, por_queme_ele_eh_comido(a) - quem_ele_come(b)

const int maxn = 4e5 + 5 ; 

int n, t, k ; 
int pai[maxn], sz[maxn] ; 

int quem_ele_come(int a){ return a + n ; }
int por_quem_ele_eh_comido(int a){ return a + 2*n ; }

struct DSU{

    int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

    void join(int a, int b){
        a = find(a), b = find(b) ; 
        if(a == b) return ; 
        if(sz[a] > sz[b]) swap(a, b) ; 
        pai[a] = b ; sz[b] += sz[a] ; 
    }

} dsu ; 

bool come(int a, int b){ //a -> b 
    if(dsu.find(quem_ele_come(a)) == dsu.find(b)) return 1 ;
    if(dsu.find(por_quem_ele_eh_comido(b)) == dsu.find(a)) return 1 ; 
    if(dsu.find(por_quem_ele_eh_comido(a)) == dsu.find(quem_ele_come(b))) return 1 ;  
    return 0 ; 
}

int add_f(int a, int b){
    if(a > n || b > n || a <= 0 || b <= 0) return 1 ;  
    // se a come b ou b come a 
    if(come(a, b)) return 1 ; 
    if(come(b, a)) return 1 ; 
    dsu.join(a, b) ; dsu.join(quem_ele_come(a), quem_ele_come(b)) ; dsu.join(por_quem_ele_eh_comido(a), por_quem_ele_eh_comido(b)) ; 
    return 0 ; 
}

int add_k(int a, int b){
    if(a > n || b > n || a <= 0 || b <= 0) return 1 ; 
    if(dsu.find(a) == dsu.find(quem_ele_come(b))) return 1 ; 
    if(dsu.find(b) == dsu.find(por_quem_ele_eh_comido(a))) return 1 ; 
    if(dsu.find(a) == dsu.find(b) || dsu.find(quem_ele_come(a)) == dsu.find(quem_ele_come(b))) return 1 ; // sao do mesmo tipo
    if(dsu.find(por_quem_ele_eh_comido(a)) == dsu.find(por_quem_ele_eh_comido(b))) return 1 ;
    dsu.join(quem_ele_come(a), b) ; dsu.join(por_quem_ele_eh_comido(b), a) ; dsu.join(quem_ele_come(b), por_quem_ele_eh_comido(a)) ; 
    return 0 ; 
}

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> t ; 

    while(t--){
        
        cin >> n >> k ; 

        int ans = 0 ; 

        for(int i = 1 ; i <= 3*n ; i++) pai[i] = i, sz[i] = 1 ; 

        for(int i = 1 ; i <= k ; i++){
            int type, a, b ; cin >> type >> a >> b ; 
            if(type == 1){ // mesmo tipo 
               ans += add_f(a, b) ;  
            }
            else{ // a mata b 
                ans += add_k(a, b) ; 
            }
        }

        cout << ans << "\n" ; 

    }

}

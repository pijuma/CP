/*
pode mover pra esq pra dir 
inserir algum elemento na esq na dir e imprimir o valor 
que ta agr 
*/
#include<bits/stdc++.h>
using namespace std ; 

#define ll long long 

const int maxn = 2e5 + 5 ; 

int n, at_pos ; 
int v[maxn]; 

struct L{
    int x ; 
    struct L *ant, *prox ; 
    L(int val, L *ant){
        this->x = val ; 
        this->ant = ant ; 
        this->prox = NULL ; 
    }
    //L(int val, L *ant = nullptr) : x(val), ant(ant), prox(nullptr) {}
} ;

    void add_nxt(L *ant, L *prox){
        ant->prox = prox ; 
    }

    void insert_left(L *at, int val){
        L *bef = at->ant ; 
        L *newnode = new L(val, bef) ; 
        if(bef != NULL){
            add_nxt(bef, newnode) ; 
        }
        newnode->prox = at ; 
        at->ant = newnode ;
    }

    void insert_right(L *at, int val){
        //cout << "right " << at->x << "\n" ; 
        L *newnode = new L(val, at) ;
        newnode->prox = at->prox ; 
        if(newnode->prox != NULL){
            //cout << (at->prox)->x << "\n" ;
            //cout << ((at->prox)->ant)->x << "\n" ;
            (at->prox)->ant = newnode ;
        }
        at->prox = newnode ;  
    }

int main(){

    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
    cin >> n >> at_pos ; 

    L *ant = NULL ; 
    L *first = NULL ; 

    for(int i = 1 ; i <= n ; i++){
        cin >> v[i] ; 
        L *node_at = new L(v[i], ant) ;
        if(first == NULL) first = node_at ; 
        if(ant != NULL){
            add_nxt(ant, node_at) ;
        } 
        ant = node_at ; 
    }

    int q; cin >> q; 

    L *atual = first ; 

    while(1){
        if(at_pos <= 1) break ; 
        at_pos-- ; 
        if(atual->prox != NULL) atual = atual->prox ; 
    }

    for(int i = 1 ; i <= q ; i++){
        string s ;cin >> s ;
        if(atual == NULL) continue ;  
        if(s == "moveLeft"){
            if(atual->ant != NULL) atual = atual->ant ; 
        }
        else if(s == "moveRight"){
            if(atual->prox != NULL) atual = atual->prox ; 
        }
        else if(s == "insertLeft"){
            int x ; cin >> x ;
            insert_left(atual, x) ; 
        }
        else if(s == "insertRight"){
            int x ; cin >> x ;
            insert_right(atual, x) ; 
        }
        else{
            cout << atual->x << "\n" ; 
        }
    }

}

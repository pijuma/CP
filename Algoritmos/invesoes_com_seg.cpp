#include<bits/stdc++.h>

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 60005 ; 
int inv, tree[4*maxn], v[maxn]; 

struct SEG{

    void att(int no, int i, int j, int pos){
        if(i == j && i == pos){
            tree[no] = 1 ;
            return ;  
        }
        if(pos <= meio) att(esq, i, meio, pos) ; 
        else att(dir, meio + 1, j, pos) ; 
        tree[no] = tree[esq] + tree[dir] ; 
    }

    int query(int no, int i, int j, int a, int b){
        if(a > j || i > b) return 0 ; 
        if(a <= i && b >= j) return tree[no] ; 
        return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ; 
    }

} seg ; 

int main(){

	int n ; 
	cin >> n ; 
	for(int i = 1, a ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= n ; i++){
        inv += seg.query(1, 1, n, v[i] + 1, maxn - 5) ; 
        seg.att(1, 1, n, v[i]) ; 
    }

	cout << inv << "\n" ; 

}
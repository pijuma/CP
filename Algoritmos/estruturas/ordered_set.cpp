// link: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/ 
#include<bits/stdc++.h>
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 
using namespace __gnu_pbds ;

const int maxn = 2e5 + 5 ; 

int n, cam[3][maxn] ; 
ll ans ; 
int id[maxn] ; 
ordered_set Tree[4*maxn] ; 

bool cmp(int a, int b){ return cam[0][a] < cam[0][b] ; } // sorta por a guarda c na seg c b 

struct SEG{

	void upd(int no, int i, int j, int pos, int val){
	
		Tree[no].insert(val) ; 

		if(i == j) return ; 
		if(pos <= meio) upd(esq, i, meio, pos, val) ; 
		else upd(dir, meio + 1, j, pos, val) ; 
	
	}

	ll query(int no, int i, int j, int pos, int val){
		if(i > pos) return 0 ; 
		if(j <= pos) return Tree[no].order_of_key(val) ; 
		return query(esq, i, meio, pos, val) + query(dir, meio + 1, j, pos, val) ;
	}

} seg ; 

int main(){

	cin >> n ; 

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 1 ; j <= n ; j++){
			int x ; 
			cin >> x ; 
			cam[i][x] = j ; 
		}
	}

	for(int i = 1 ; i <= n ; i++) id[i] = i ; 

	sort(id + 1, id + 1 + n, cmp) ; 

	for(int i = 1 ; i <= n ; i++){
		ans += seg.query(1, 1, n, cam[1][id[i]], cam[2][id[i]]) ; 
		seg.upd(1, 1, n, cam[1][id[i]], cam[2][id[i]]) ; 
	}

	cout << ans << "\n" ; 

}

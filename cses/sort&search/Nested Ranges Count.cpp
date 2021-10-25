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

int n, k, t, p ; 
ordered_set s ; 

int main(){

	cin >> n >> k ; 
	t = ++n ; 

	for(int i = 1 ; i <= n ; i++) s.insert(i) ; 

	while(--t){
		p = (p + k)%t ; 
		cout << *s.find_by_order(p) << " " ;
		s.erase(s.find_by_order(p)) ; 
	}

	cout << "\n" ; 

}

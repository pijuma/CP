#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e3 + 5 ; 
int n, m, sum, a, b, mark[maxn] ;

int32_t main(){

	while(scanf("%lld%lld", &n,&m) != EOF){
		sum = 0 ; 
		memset(mark, 0, sizeof mark) ; 
		for(int i = 1 ; i <= m ; i++){
			cin >> a >> b ; 
			for(int j = a ; j < b ; j++) mark[j] = 1 ; 
		}
	    for(int i = 1 ; i <= n ; i++){
	    	if(!mark[i]) continue ; 
	    	int j = i ; 
	    	for(j = i ; j <= n ; j++){
	    		if(!mark[j]) break ; 
	    	}
	    	sum += 2*(j-i) ; 
	    	i = j ; 
	    } 
		cout << sum + n + 1 << "\n" ; 
	} 

}

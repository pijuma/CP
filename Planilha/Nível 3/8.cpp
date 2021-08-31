#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 505 ; 

int n, m, v[maxn] ;
double ans ; 
int main(){

	scanf("%d%d",&n,&m) ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; double c ; 
		scanf("%d%d%lf", &a, &b, &c) ; 
		ans = max(ans, 1.00*(v[a] + v[b])/c) ; 
	}

	printf("%.9lf\n", ans) ; 

}

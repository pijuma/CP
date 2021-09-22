#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int maxa = 1e7 ; 
const int inf = 1e9 ; 

int n, m, a, b, c, d[maxn] ; 
vector<int> u, v, p ; 

bool busca(double x){

	for(int i = 0 ; i <= n ; i++) d[i] = inf ; 

	d[u[0]] = 0 ; 
    
    for(int i = 0 ; i < n ; i++){
    	for(int j = 0 ; j < m ; j++){
    		if(d[u[j]] + p[j] - x < d[v[j]]){
    			d[v[j]] = d[u[j]] + p[j] - x ;
    		}
    	}
    }

    for(int i = 0 ; i < m ; i++){
    	if(d[u[i]] - x + p[i] < d[v[i]]) return true ; 
    }

    return false ; 

}

int main(){

	scanf("%d%d", &n, &m) ;

	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &a, &b, &c) ; 
		u.push_back(a), v.push_back(b), p.push_back(c) ; 
	} 

	double ini = 0, mid, fim = maxa, best = 0 ; 

	while((fim - ini) > 0.001){
		mid = (ini + fim)/2 ; 
		if(busca(mid)) best = mid, fim = mid ; 
		else ini = mid ; 
	}

	printf("%.3lf\n", best) ; 

}

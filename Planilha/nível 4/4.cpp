#include<bits/stdc++.h>
#define int long long
using namespace std ; 
const int maxn = 1e5 + 5 ; 

int n, m, a, money[maxn], b[maxn] ;

bool ok(int x){
	
	int need = 0 ;
	for(int i = 1, j = x ; i <= x ; i++, j--){
		if(b[j] > money[i]) need += b[j] - money[i] ;
	}

	return need <= a ; 

}

int calc(int x){
	
	int val = 0, tot = 0 ; 
	
	for(int i = 1, j = x ; i <= x ; i++, j--) tot += b[j] ; 

	return max(0LL, tot - a) ; 
}

pair<int,int> bb(){

	int ini = 0, fim = min(n, m), mid ;
	pair<int,int> best ;  

	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		if(ok(mid)){
			best = {mid, calc(mid)}, ini = mid + 1 ;
		}  
		else fim = mid - 1 ; 
	}

	return best ; 
}

int32_t main(){

	cin >> n >> m >> a ; 

	for(int i = 1 ; i <= n ; i++) cin >> money[i] ; 
	for(int i = 1 ; i <= m ; i++) cin >> b[i] ; 

	sort(money + 1, money + 1 + n) ; reverse(money + 1, money + 1 + n) ; // ordem decrescente  
    sort(b + 1, b + 1 + m) ; // ordem crescente de valor 

    cout << bb().first << " " << bb().second << "\n" ;

}

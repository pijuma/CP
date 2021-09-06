#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 4 ; 
const int inf = 1e9 ; 

int n, m, k, l ; 
vector<int> c ; 
map<int,int> f, ant ; 

int solve(int k, int sum){

	int ct = 0 ; 

	for(int i = 0 ; i < c.size() ; i++){
		if(!k) break ;
		int v = sum - c[i] ; 
		if(f[v] <= 0 || v < 0 || f[c[i]] <= 0) continue ; 
		if(v == c[i] && f[v] - 1 <= 0) continue ;
		f[v]--, f[c[i]]-- ; 
		if(v == 0) ct++ ; 
		else ct += 2 ; 
		k-- ; 
	}
	
	if(k) return inf ; 
	else return ct ; 

}

int32_t main(){

	while(true){
		cin >> n >> m ; 
		if(!n && !m) return 0 ;
		cin >> l ; // largura tabuas  
		cin >> k ; 
		f.clear(), ant.clear() ; 
		f[0] = ant[0] = inf ;  
		c.clear() ; 
		for(int i = 1 ; i <= k ; i++){
			int a ; 
			cin >> a ;
			c.push_back(a) ;  
			f[a]++ ;
			ant[a]++ ;
		} 
		sort(c.begin(), c.end()) ; 
		reverse(c.begin(), c.end()) ;
		int resp = inf ; 
		if(!((n*100)%l)) resp = min(resp, solve((n*100)/l, m)) ; // vertical
		for(int i = 0 ; i < c.size() ; i++) f[c[i]] = ant[c[i]] ; 
		if(!((m*100)%l)) resp = min(resp, solve(((m*100)/l), n)) ; // horizontal 
		if(resp >= inf || resp < 0) cout << "impossivel\n" ; 
		else cout << resp << "\n" ; 
	}

}

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 405 ; 

int n, vis[maxn*maxn], w[maxn*maxn], sumd ; 
pair<int,int> x[maxn] ; 

bool cmp(pair<int,int>a, pair<int,int>b){
	if(a.first + a.second != b.second + b.first) return a.first + a.second < b.second + b.first ; 
	return a.first < b.first ; 
}

bool solve(int ignore){
	int id = 1, oid ; 
	vis[0] = 1, w[0] = 0 ;  
	for(int i = 0 ; i < n ; i++){
		if(i == ignore) continue ; 
		int u = x[i].second - x[i].first ; 
		oid = id ; 
		for(int j = 0 ; j < id ; j++){
			if(!vis[u+w[j]]){
				vis[u+w[j]] = 1 ; 
				w[oid++] = u + w[j] ; 
			}
		}
		id = oid ; 
	}
	return vis[sumd/2] ; 
}

int main(){

	while(true){
		
		cin >> n ; 

		if(!n) return 0 ; 
		bool ok = 0 ; 
		int tot = 0 ; sumd = 0 ; 
		for(int i = 0 ; i < n ; i++){
			int a, b ; 
			cin >> a >> b ; 
			if(a > b) swap(a, b) ; 
			x[i] = {a, b} ; 
			sumd += (b-a) ; 
			tot += (a+b) ; 
		}
		sort(x, x + n, cmp) ; 
		for(int i = -1 ; i < n ; i++){ // qual vou ignorar
			if(i >= 0) sumd -= (x[i].second - x[i].first) ; 
			if(sumd%2 != 0){ // impar n tem como 
				if(i >= 0) sumd += (x[i].second - x[i].first) ; 
				continue ; 
			}
			memset(vis, 0, sizeof vis) ; 
			if(solve(i)){
				ok = 1 ;
				if(i == -1) cout << tot/2 << " " << "discard none\n" ;
				else cout << (tot - x[i].first - x[i].second)/2 << " " << "discard" << " " << x[i].first << " " <<  x[i].second << "\n" ;
				break ;  
			}
			sumd += x[i].second - x[i].first ; // volta o valor 
		}
		if(!ok) cout << "impossible\n" ; 
	}

}

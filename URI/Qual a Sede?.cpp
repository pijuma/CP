#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int A, n, s, q, dist[maxn], k, sede[maxn] ; 

struct cara{
	int med, temp ; 
} ; 
 
cara kra[maxn] ; 
vector<int> grafo[maxn] ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	queue<int> fila ; 

	cin >> n >> s >> q >> A ; 

	for(int i = 1 ; i <= s ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ;
		fila.push(a) ; 
		if(!dist[a]){
			dist[a] = 1 ; 
			sede[a] = i ; 
			kra[a] = {b, c} ;  
		} 

		else{
			if(kra[a].med < b){
				sede[a] = i ; 
				kra[a] = {b, c} ; 
			}
			else if(kra[a].med == b && kra[a].temp < c){
				sede[a] = i ; 
				kra[a] = {b, c} ; 
			}
		}

	}

	for(int i = 1 ; i <= A ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	while(!fila.empty()){

		int at = fila.front() ; fila.pop() ; 

		for(auto a : grafo[at]){
			if(!dist[a] || dist[a] > dist[at] + 1){
				dist[a] = dist[at] + 1 ;
				kra[a] = kra[at] ;  
				sede[a] = sede[at] ; 
				fila.push(a) ; 
			}
			else if(dist[a] == dist[at] + 1){
				if(kra[a].med < kra[at].med){
					kra[a] = kra[at] ; 
					sede[a] = sede[at] ; 
				}
				else if(kra[a].med == kra[at].med && kra[a].temp < kra[at].temp){
					kra[a] = kra[at] ; 
					sede[a] = sede[at] ; 
				}
			}
		}

	}

	for(int i = 1 ; i <= q ; i++){
		int x ; 
		cin >> x ; 
		int ans = sede[x] ; 
		if(ans == 0 && dist[ans] == 0) cout << "Noic" << endl ; 
		else cout << ans << "\n" ; 
 	}


}

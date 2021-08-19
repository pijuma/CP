#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// lower bound pega o 1o maior ou igual p pegar menor ou igual usa - val 

const int maxn = 2e5 + 5 ; 

int n, k, resp ; 
multiset<int> times ; 
pair<int,int> filmes[maxn] ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> n >> k ; 

	for(int i = 0 ; i < n ; i++){
		
		int l, r ; 
		cin >> l >> r ; 

		filmes[i] = {r, l} ; // pegar oq termina antes é smp otimo
	}

	sort(filmes, filmes + n) ; 

	while(k--) times.insert(0) ; 

	for(int i = 0 ; i < n ; i++){

		auto a = filmes[i] ; 
		auto it = times.lower_bound(-a.second) ; // qual o 1o cara q termina antes de eu começar

		if(it != times.end()){ // se tiver algm eu pss assistir c meu cara
			resp++ ; 
			times.erase(it) ; 
			times.insert(-a.first) ; 
		}

	}

	cout << resp << "\n" ; 

}

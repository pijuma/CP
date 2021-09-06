#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 

int n, m, a[maxn], b[maxn] ; 
map<int,int> mpa, mpb ; 

void solve(){

	mpa.clear(), mpb.clear() ;

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		 mpa[a[i]]++ ;
	}  
	for(int i = 1 ; i <= m ; i++){
		cin >> b[i] ;
		 mpb[b[i]]++ ; 
	} 

	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m) ; 

	int cta = 0, ctb = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		if(a[i] == a[i-1]) continue ; 
		cta += !mpb[a[i]] ;
	}

	for(int i = 1 ; i <= m ; i++){
		if(b[i] == b[i-1]) continue ; 
		ctb += !mpa[b[i]] ;
	}

	cout << min(cta, ctb) << "\n" ; 

}

int main(){

	while(true){
		cin >> n >> m ; 
		if(!n && !m) return 0 ; 
		solve() ;
	}

}

#include<bits/stdc++.h>
using namespace std ; 

// uma estação a cada 1km 
// t teletransportadores 
// se a pos ini é i e do trasnportador é j 
// ele irá parar em 2j - i 
// dado ini e fim queremos saber se é possivel ou n 

const int maxn = 1e5 + 5 ; 

int t, q, g, v[maxn] ;

int main(){

	while(true){
		cin >> t >> q ; 
		if(!t && !q) return 0 ;
		for(int i = 1 ; i <= t ; i++) cin >> v[i] ; 
		sort(v + 1, v + 1 + t) ; 
	    if(t > 1) g = abs(v[1] - v[2]) ; 
	    for(int i = 2 ; i <= t ; i++) g = __gcd(g, abs(v[i] - v[i-1])) ; 
	    vector<char> resp ;
	    while(q--){
	    	bool ans = 0 ; 
	    	int s, d ; 
	    	cin >> s >> d ; 
	    	if(t == 1) ans = (d == 2*v[1] - s) ;
	    	else if(((d - s)/2) % g == 0) ans = 1 ; 
	    	else{
	    		d = (d + s)/2 ; 
	    		for(int i = 1 ; i <= t ; i++){
	    			if((d-v[i]) % g == 0){
	    				ans = 1 ; 
	    				break ; 
	    			}
	    		}
	    	}
	    	if((s&1) != (d&1)) ans = 0 ; 
	    	resp.push_back((ans ? 'Y' : 'N')) ; 
	    } 
	    char last = resp.back() ; resp.pop_back() ; 
	    for(auto a : resp) cout << a << " " ; 
	    cout << last << "\n" ; 
	}

}

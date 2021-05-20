#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, k, pos, l, v[maxn], r, val ; 
int bit[maxn][3] ; 
char tipo ; 

struct BIT{
	
	void upd(int pos, int tipo){
		for(; pos < maxn ; pos += pos&-pos) bit[pos][tipo]++ ; 
	}

    void upd2(int pos, int tipo){
		for(; pos < maxn ; pos += pos&-pos) bit[pos][tipo]-- ; 
	}

	int query(int pos, int tipo){
		int tot = 0 ; 
		for(; pos > 0 ; pos -= pos&-pos) tot += bit[pos][tipo] ; 
		return tot ; 
	}

} Bit ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	while(cin >> n >> k){
		
		string ans ; 

		for(int i = 0 ; i < maxn ; i++) bit[i][0] = bit[i][1] = bit[i][2] = 0 ; 

    	for(int i = 1, x ; i <= n ; i++){
    		cin >> v[i] ;  
    		if(v[i] < 0) v[i] = 2 ; 
    		else if(v[i] > 0) v[i] = 1 ; 
		    Bit.upd(i, v[i]) ;  
	    }

    	for(int i = 1 ; i <= k ; i++){
		    cin >> tipo ; 
		    if(tipo == 'C'){
		    	cin >> pos >> val ; 
		    	if(val > 0) val = 1 ; 
		    	else if(val < 0) val = 2 ;  
		    	Bit.upd(pos, val), Bit.upd2(pos, v[pos]) ; 
		    	v[pos] = val ; 
		    }
		    else{
		    	cin >> l >> r ; 
			    int qtd11 = Bit.query(r, 2) - Bit.query(l-1, 2) ; 
			    int qtd1 = Bit.query(r, 1) - Bit.query(l-1, 1) ; 
			    int qtd0 = Bit.query(r, 0) - Bit.query(l-1, 0) ; 
			    if(qtd0 != 0) ans.push_back('0') ;  
			    else if(qtd11%2) ans.push_back('-') ; 
			    else ans.push_back('+') ; 
		    }
	    }

	    cout << ans << "\n" ; 

	}

}

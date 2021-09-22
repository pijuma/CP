#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 6e4 + 5 ; 

int n, bit[maxn], ans ; 

struct BIT{

	void upd(int pos, int v){
		for(; pos > 0 ; pos -= pos&-pos) bit[pos] += v ;  
	}

    int query(int pos){
    	int tot = 0 ; 
    	for(; pos < maxn ; pos += pos&-pos) tot += bit[pos] ; 
    	return tot ; 
    }

} Bit ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		int x ; 
		cin >> x ; 
		ans += Bit.query(x+1) ;
		Bit.upd(x, 1) ;  
	}

	cout << ans << "\n" ; 

}

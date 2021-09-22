#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, bit[maxn] ; 

struct BIT{

	void upd(int pos, int val){
		for(; pos < maxn ; pos += pos&-pos) bit[pos] += val ; 
	}
    
    int query(int pos){
    	int tot = 0 ; 
    	for(; pos > 0 ; pos -= pos&-pos) tot += bit[pos] ; 
    	return tot ; 
    }

} Bit ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		int x ;
		cin >> x ;
		Bit.upd(i, x) ;  
	}

	cout << Bit.query(n) << "\n" ; 

}

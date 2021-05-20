#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1010 ; 

int t, n ; 
int bit[maxn][maxn] ; 

struct BIT{

	void upd(int x, int y, int val){
		for(int i = x ; i < maxn ; i += i&-i){
			for(int j = y ; j < maxn ; j += j&-j){
				bit[i][j] = max(bit[i][j], val) ; 
			}
		}
	}

	int query(int x, int y){
		int tot = 0 ; 
		for(int i = x ; i > 0 ; i -= i&-i){
			for(int j = y ; j > 0 ; j -= j&-j){
				tot = max(tot, bit[i][j]) ; 
			}
		}
		return tot ; 
	}

} Bit ; 

int main(){

	cin >> t ; 

	while(t--){

		for(int i = 0 ; i < maxn ; i++){
			for(int j = 0 ; j < maxn ; j++){
				bit[i][j] = 0 ; 
			}
		}

		cin >> n ; 

		for(int i = 1, x, y ; i <= n ; i++){
			cin >> x >> y ; 
			Bit.upd(x, y, Bit.query(x, y)+1) ; 
		}

		cout << Bit.query(maxn-1, maxn-1) << "\n" ; 

	}

}

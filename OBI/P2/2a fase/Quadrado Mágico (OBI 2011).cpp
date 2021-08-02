#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, v[maxn][maxn], sum, atsum ; 
bool ok ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){

		for(int j = 1 ; j <= n ; j++){

			cin >> v[i][j] ; 

		}

	}

	for(int i = 1 ; i <= n ; i++) sum += v[i][1] ; 

	//testar linha 

	ok = 1 ; 

	for(int i = 1 ; i <= n ; i++){

		atsum = 0 ; 

		for(int j = 1 ; j <= n ; j++) atsum += v[i][j] ; 

		if(atsum != sum) ok = 0 ; 

	}

	for(int j = 1 ; j <= n ; j++){

		atsum = 0 ; 

		for(int i = 1 ; i <= n ; i++) atsum += v[i][j] ;

		if(atsum != sum) ok = 0 ; 

	}

	atsum = 0 ; 

	for(int i = 1 ; i <= n ; i++) atsum += v[i][i] ; 

	if(atsum != sum) ok = 0 ; 
    
    if(ok) cout << sum << "\n" ; 
    else cout << "0\n" ; 
    
}

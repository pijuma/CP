#include<bits/stdc++.h>
using namespace std ; 

int n, t1, t2, p, m ; 

int main(){

	cin >> n ; 

	for(int i = 1, x ; i <= n ; i++){
		cin >> x ; 
		(x == 1 ? t1++ : t2++) ; 
	}

	cin >> p >> m ; 

	if(t1 >= p && t2 >= m) cout << "S\n" ; 
	else cout << "N\n" ;  
}

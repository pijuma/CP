#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

struct P{
	int x, y ; 
} ; 

int n, x, y ; 
P p[maxn] ; 

int main(){

	while(true){
		cin >> n ; 
		if(!n) return 0 ; 
		cin >> x >> y ; 
		for(int i = 1 ; i <= n ; i++){
			int a, b ; 
			cin >> a >> b ; 
			a -= x, b -= y ; 
			if(!a || !b) cout << "divisa\n" ; 
			else if(a > 0 && b > 0) cout << "NE\n" ; 
			else if(a < 0 && b < 0) cout << "SO\n" ; 
			else if(a > 0 && b < 0) cout << "SE\n" ; 
			else cout << "NO\n" ;
		}
	}

}

#include<bits/stdc++.h>
using namespace std ; 

int X1, x2, Y1, y2, a, b, c, t, met, d, x, y, n; 

int main(){

	while(true){
		cin >> a >> c >> b >> d ; 
		X1 = min(a, b), x2 = max(a, b) ;
		Y1 = min(c, d), y2 = max(c, d) ; 
		if(!X1 && !x2 && !Y1 && !y2) return 0 ;
		cin >> n ;  
		cout << "Teste " << ++t << "\n" ; 
		met = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			cin >> x >> y ; 
			if(x >= X1 && x <= x2 && y >= Y1 && y <= y2) met++ ; 
		}
		cout << met << "\n\n" ; 
	}

}

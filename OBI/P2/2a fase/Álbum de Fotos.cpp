#include<bits/stdc++.h>
using namespace std ; 

// 2 fts por pagina 
// fts podem ser giradas mas a modo paralelo sempre ao caderno 

int h, l, a1, b1, a2, b2 ; 
	

int main(){

	cin >> l >> h ; //largura e alt do algum 

	cin >> a1 >> b1 ; 
	cin >> a2 >> b2 ; 

	// duas normais


    if(a1 + a2 <= h && max(b1, b2) <= l) cout << "S\n" ; 
	else if(a1 + a2 <= l && max(b1, b2) <= h) cout << "S\n" ;
	else if(b1 + b2 <= h && max(a1, a2) <= l) cout << "S\n" ;
	else if(b1 + b2 <= l && max(a1, a2) <= h) cout << "S\n" ;  
	else if(b1 + a2 <= h && max(b2, a1) <= l) cout << "S\n" ; 
	else if(b1 + a2 <= l && max(b2, a1) <= h) cout << "S\n" ; 
	else if(a1 + b2 <= h && max(b1, a2) <= l) cout << "S\n" ; 
	else if(a1 + b2 <= l && max(b1, a2) <= h) cout << "S\n" ;   
	else cout << "N\n" ; 

}

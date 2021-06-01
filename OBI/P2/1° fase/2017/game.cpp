#include<bits/stdc++.h>
using namespace std ; 

int a, n, d ; 

int main(){

	cin >> n >> d >> a ; 

	if(d >= a) cout << d - a << "\n" ; 
	else cout << n - a + d << "\n" ;
	
}

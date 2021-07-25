// Extended Euclidean algorithm
#include<bits/stdc++.h>
using namespace std ; 

int gcd(int a, int b, int &x, int &y){
	
	if(!b){
		x = 1, y = 0 ; 
		return a ; 
	}

	int x1, y1 ; 

	int d = gcd(b, a%b, x1, y1) ; 

	x = y1 ; 
	y = x1 - y1*(a/b) ; 

	return d ; 

}

int main(){

	cin >> a >> b ;

	int a1, b1 ; 

	cout << gcd(a, b, a1, b1) << "\n" ; 
	
}

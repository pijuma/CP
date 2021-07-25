// Extended Euclidean algorithm to find if a Linear Diophantine Equation has a solution 
#include<bits/stdc++.h>
using namespace std ; 

int gcd(int a, int b, int &x, int &y){

	if(!b){
		x = 1, y = 0 ; 
		return a ; 
	}

	int x1, y1 ; 
	int d = gcd(a, b, x1, y1) ; 

	x = y1, y = x1 - y1*(a/b) ; 

	return d ; 

}

int main(){

	cin >> a >> b ; 

	int x0, y0 ; 

	int g = gcd(abs(a), abs(b), x0, y0) ; 

	if(c%g) cout << "0\n" ; 

	int div = c/g ;

	x0 *= div, y0 *= div ; 

	if(a < 0) x0 = -x0 ; 
	if(b < 0) y0 = -y0 ; 

	cout << "Tem\n" ; 
 
}

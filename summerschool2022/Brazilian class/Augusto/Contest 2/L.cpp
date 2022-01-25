#include<bits/stdc++.h>
using namespace std ; 

long long n, h ; 

int main(){

	cout.precision(10) ; 

	cin >> n >> h ; 
	
	for(int i = 1 ; i < n ; i++){
		long double q = (long double)i/(long double)n ; 
		cout << sqrt(q)*(long double)h << " " ; 
	}

	cout << "\n" ; 

}

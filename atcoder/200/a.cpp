#include<bits/stdc++.h>
using namespace std ; 

int n, sum ; 
string s ; 

int main(){

	cin >> n ; 
	
	sum = n/100 ; 

	if(n%100) sum++ ; 
 
	cout << sum << "\n" ; 

}
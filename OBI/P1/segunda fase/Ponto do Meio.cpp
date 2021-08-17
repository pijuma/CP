#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int n, lado ; 

int32_t main(){

	cin >> n ; 

	lado = 2 ; 

	while(n--) lado += (lado - 1) ; 

	cout << lado*lado << "\n" ; 

}

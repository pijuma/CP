#include<bits/stdc++.h>
using namespace std ; 

int n ; 

int main(){

	vector<int> v ; 

	cin >> n ; 

	int s = 0 ; 

	for(int i = 1, a ; i <= n ; i++){
		cin >> a ; 
		s += a ; 
		v.push_back(a) ; 
	} 

	int a1 = (2*s + 2*n - (n*n))/(2*n) ;

	// cout << a1 << "\n" ; 

	int qtd = 0, dif = 0 ;

	for(int i = 0 ; i < n ; i++){
		if(v[i] != a1 + i) dif += abs(v[i]-a1-i) ; 
		qtd += (v[i] - a1-i) ; 
	} 

	if(qtd == 0) cout << dif/2 << "\n" ; 
	else cout << "-1\n" ; 

}

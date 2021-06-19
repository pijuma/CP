#include<bits/stdc++.h>
using namespace std ; 

int v, t, s, d ; 

int main(){

	cin >> v >> t >> s >> d ; 

	int t0 = v*t ; 
	int t1 = v*s ;

	if(d >= t0 && d <= t1) cout << "No\n" ; 
	else cout << "Yes\n" ; 

}
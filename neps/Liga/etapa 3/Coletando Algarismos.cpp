#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int last, sum ; 
string num ; 

int32_t main(){

	cin >> num ;

	last = 0 ; 

	for(int i = 0 ; i < num.size() ; i++){
		int atu = num[i] - '0' ; 
		if(last > atu) swap(atu, last) ; 
		sum += min(abs(atu - last), 9-atu+last+1) ; 
		// cout << abs(atu - last) << " " <<  9-atu+last << " " << sum << "\n" ; 
		last = num[i] - '0' ; 
	} 

	cout << sum << "\n" ; 

}

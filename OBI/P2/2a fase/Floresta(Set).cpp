#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

int n, res ; 
set<pair<int,int>> s ; 

int32_t main(){

	cin >> n ; 

	for(int i = 2 ; i * i <= n ; i++){
		if((n + i - 1)%(2*i - 1) == 0)  s.insert({min((n + i - 1)/(2*i - 1), i), max((n + i - 1)/(2*i - 1), i)}) ; 
	}

	cout << s.size() << "\n" ; 

}

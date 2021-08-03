#include<bits/stdc++.h>

#define int long long 

using namespace std ; 

// P -> 2
// C -> 2
// A -> 1  
// D -> 0 

int n, sum ; 
string s ; 

int32_t main(){

	cin >> n >> s ; 

	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'P') sum += 2 ; 
		if(s[i] == 'C') sum += 2 ; 
		if(s[i] == 'A') sum++ ; 
	}

	cout << sum << "\n" ; 

}

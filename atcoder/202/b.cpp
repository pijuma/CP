#include<bits/stdc++.h>
using namespace std ; 

string s ; 

int main(){

	cin >> s ; 
	
	reverse(s.begin(), s.end()) ; 
	// cout << s << "\n" ; 
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '6') s[i] = '9' ; 
		else if(s[i] == '9') s[i] = '6' ; 
	}

	cout << s << "\n" ; 

}
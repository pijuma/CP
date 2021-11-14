// comeca pela menor q der 
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e6 + 5 ; 
const int prime = 37 ; 
const int mod = 1e9 + 7 ;

string s ; 

int main(){

	cin >> s ; 

	s = s + s ; 

	int ans = 0, i = 0 ; 

	while(i < s.size()/2){
		ans = i ; 
		int k = i, j = i + 1 ; 
		while(j < s.size() && s[j] >= s[k]){
			if(s[j] == s[k]) k++ ; 
			else k = i ; 
			j++ ; 
		}
		while(i <= k) i += (j-k) ; 
	} 

	cout << s.substr(ans, s.size()/2) << "\n" ; 

}

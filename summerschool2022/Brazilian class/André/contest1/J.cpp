#include<bits/stdc++.h>
using namespace std ; 

string x, s ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> x ;

	bool ans = 0 ; 

	vector<string> anss ; 

	for(int i = 0 ; i < x.size() ; i++){
		for(int j = i ; j < x.size() ; j++){
			string s = x ; 
			if(i == j) continue ;
			if(i == 0 && s[j] == '0') continue ;  
			if(s[i] - '0' > s[j] - '0'){
				swap(s[i], s[j]) ; 
				anss.push_back(s) ; 
				ans = 1 ; 
			}
		}
	}

	if(ans) sort(anss.begin(), anss.end()) ; 

	// for(auto a : anss) cout << a << " " ; 
	// cout << "\n" ;

	if(ans) cout << anss[anss.size()-1] << "\n" ; 
	else cout << "-1\n" ; 

}

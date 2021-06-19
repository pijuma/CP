#include<bits/stdc++.h>
using namespace std ; 

int n, h ;
string s ; 
vector<pair<int,string>> v ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> s >> h ; 
		v.push_back({h, s}) ; 
	}

	sort(v.begin(), v.end()) ; 

	cout << v[v.size() - 2].second << "\n" ; 

}
#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int maxn = 5e3 + 5 ; 
 
int n, x ;
vector<pair<int,int>> v ;  
map<int,int> f ; 
 
int32_t main(){
 
	cin >> n >> x ; 
 
	v.push_back({0, 0}) ; 
 
	for(int i = 1, a ; i <= n ; i++){
		cin >> a ; 
		v.push_back({a, i}) ; 
	}
 
	sort(v.begin(), v.end()) ; 
 
	for(int i = 1 ; i <= n ; i++){
		int l = 1, r = n ;  
		int sum = x - v[i].first ;
		while(r != l){
			if(i != l && i != r && v[l].first + v[r].first == sum){
				cout << v[i].second << " " << v[l].second << " " << v[r].second << "\n" ; 
				return 0 ; 
			}
			if(v[l].first + v[r].first < sum) l++ ; 
			else r-- ; 
		} 
	} 
 
	cout << "IMPOSSIBLE\n" ; 
 
}

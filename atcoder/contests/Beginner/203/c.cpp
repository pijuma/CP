#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int n, k, a, b, sum, last ; 
vector<pair<int,int>> v ; 

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a >> b ; 
		v.push_back({a, b}) ; 
	}

	sort(v.begin(), v.end()) ; 

	sum = k, last = 0 ; 

	for(int i = 0 ; i < n ; i++){
		if(sum < abs(last - v[i].first)){
			last += sum ; 
			cout << last << "\n" ; 
			return 0 ;  
		}
		sum -= abs(last - v[i].first) ; 
		last = v[i].first ; 
		sum += v[i].second ;
	}

	cout << last + sum << "\n" ; 
}

#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

int n ; 

bool test(int d){
	vector<int> ans ; 
	while(d){
		ans.push_back(d%10) ; d /= 10 ; 
	}
	sort(ans.begin(), ans.end()) ; 
	for(int i = 1 ; i < ans.size() ; i++){
		if(ans[i] == ans[i-1]) return 0 ;  
	}
	return 1 ; 
}

int32_t main(){

	cin >> n ; 
	n++ ; 

	while(!test(n)) n++ ; 

	cout << n << "\n" ; 

}

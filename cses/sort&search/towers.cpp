#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

//LIS 
int n, k ; 

int main(){

	cin >> n  ;
	vector<int> v ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> k ; 
		vector<int>::iterator it = upper_bound(v.begin(), v.end(), k) ; //n decrescente 
		if(it == v.end()) v.push_back(k) ; 
		else *it = k ; 
	}

	cout << v.size() << "\n" ; 

}

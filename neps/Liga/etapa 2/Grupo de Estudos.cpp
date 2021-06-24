#include<bits/stdc++.h>
using namespace std ; 

int n ; 

int main(){

	cin >> n ; 

	set<int> v ; 

	for(int i = 1, a; i <= n ; i++){
		cin >> a ; 
		v.insert(a) ; 
	}

	cout << v.size() << "\n" ; 

}

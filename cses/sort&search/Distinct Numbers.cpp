#include<bits/stdc++.h>
using namespace std ; 
 
int n ; 
 
int main(){
 
	set<int> v ; 
	
	cin >> n ; 
 
	for(int i = 1, x ; i <= n ; i++){
		cin >> x ; 
		v.insert(x) ; 
	}
 
	cout << v.size() << "\n" ; 
 
}

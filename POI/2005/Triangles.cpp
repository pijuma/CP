#include<bits/stdc++.h>
using namespace std ; 

int n, l1, l2, l3 ; 
vector<int> v ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	l1 = -1 ; 

	while(true){

		cin >> n ; 
		if(!n) break ; 
		v.push_back(n) ; 

		if(v.size() > 50) break ;

	}

	sort(v.begin(), v.end()) ; 

	for(int i = 2 ; i < v.size() ; i++){
		if(v[i] < v[i-1] + v[i-2]){
			l1 = v[i], l2 = v[i-2], l3 = v[i-1] ; 
		}
	}

	if(l1 != -1) cout << l1 << " " << l2 << " " << l3 << "\n" ; 
	else cout << "NIE\n" ; 

}

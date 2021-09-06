#include<bits/stdc++.h>
using namespace std ; 

int n, m ; 
map<int, int> mp ; 

int main(){

	while(true){
		cin >> n >> m ; 
		vector<int> dif ; 
		mp.clear() ; 
		if(!n && !m) return 0 ; 
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				int x ; 
				cin >> x ;
				dif.push_back(x) ;  
				mp[x]++ ; 
			}
		}
		
		sort(dif.begin(), dif.end()) ; 
		dif.erase(unique(dif.begin(), dif.end()), dif.end()) ; 

		int mx = 0 ; 
		for(int i = 0 ; i < dif.size() ; i++) mx = max(mx, mp[dif[i]]) ; 

		vector<int> kras ; 
	    int mx_2 = 0 ; 
	    for(auto a : dif){
	    	if(mx != mp[a]) mx_2 = max(mx_2, mp[a]) ; 
	    } 

	    for(auto a : dif) if(mp[a] == mx_2) kras.push_back(a) ; 

	    sort(kras.begin(), kras.end()) ; 

	    for(auto a : kras) cout << a << " " ; 
	    cout << "\n" ; 

	}

}

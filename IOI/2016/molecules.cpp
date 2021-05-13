#include<bits/stdc++.h>
#include "molecules.h"
using namespace std ; 

long long sum ; 
vector<int> ans ; 
vector<pair<int,int>> v ; 

vector<int> find_subset(int l, int u, vector<int> w){

	for(int i = 0 ; i < w.size() ; i++) v.push_back({w[i], i}) ;

	sort(v.begin(), v.end()) ; 
    
    int ini = 0, fim = 0 ; 
    
    sum = v[0].first ; 

    while(ini < v.size()){
    	
    	if(sum >= l && sum <= u) break ; 
    	
    	if(sum < l){
    		if(fim + 1 < v.size()) sum += v[++fim].first ; 
    		else break ; 
    	}
    	
    	else if(sum > l) sum -= v[ini++].first ; 

    }

    if(sum < l || sum > u) return ans ; 
    while(ini <= fim) ans.push_back(v[ini++].second) ; 
    return ans ; 

}

/*int main(){

	vector<int> h ; 
	vector<int> f = {6, 8, 8, 7} ;
	h = find_subset(15, 17, f)  ; 
	for(int i = 0 ; i < h.size() ; i++) cout << h[i] << " " ; 
		cout << "\n" ; 
}*/

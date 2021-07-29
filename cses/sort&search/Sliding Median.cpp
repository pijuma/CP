#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, k, v[maxn] ; 

multiset<int> low, up ; 

void ins(int val){
	
	int mid = *low.rbegin() ; 

	if(val > mid){
		up.insert(val) ;
		if(up.size() > low.size()){
			int newlow = *up.begin() ; 
		    up.erase(up.find(newlow)) ; 
		    low.insert(newlow) ;
		} 
	}

	else{
		
		low.insert(val) ; 
		
		if(low.size() > up.size() + 1){
			int newup = *low.rbegin() ; 
			low.erase(low.find(newup)) ; 
		    up.insert(newup) ;
		}

	}

}

void ren(int val){
	if(low.find(val) != low.end()) low.erase(low.find(val)) ; 
	else up.erase(up.find(val)) ;
	if(low.size() < up.size()){
		int newlow = *up.begin() ; 
		up.erase(up.find(newlow)) ; 
		low.insert(newlow) ; 
	} 
}

int main(){

	cin >> n >> k ;

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	int l = k ; 
    
    low.insert(v[1]) ; 
    for(int i = 2 ; i <= k ; i++) ins(v[i]) ; 

    cout << *low.rbegin() << " " ; 

	for(int i = k + 1 ; i <= n ; i++){
		if(k == 1) ins(v[i]), ren(v[i-l]) ; 
		else ren(v[i-l]), ins(v[i]) ; 
		cout << *low.rbegin() << " " ; 
	}

	cout << "\n" ; 

}

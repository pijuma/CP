#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, k, v[maxn], sum, su, sl ; 
multiset<int> low, up ; 

void ins(int val){
	
	int mid = *low.rbegin() ;

	if(val > mid){
		
		up.insert(val) ; su += val ;

		if(up.size() > low.size()){
			int newlow = *up.begin() ; 
			up.erase(up.find(newlow)) ; 
			low.insert(newlow) ; 
			sl += newlow ; su -= newlow ; 
		}

	}

	else{

		low.insert(val) ; sl += val ; 

		if(low.size() > up.size() + 1){
			int newup = *low.rbegin() ; 
			low.erase(low.find(newup)) ; 
			up.insert(newup) ; 
			sl -= newup ; su += newup ; 
		}

	}

}

void ren(int val){
	
	if(low.find(val) != low.end()) low.erase(low.find(val)), sl -= val ;
	else up.erase(up.find(val)), su -= val ; 

	if(up.size() > low.size()){
		int newlow = *up.begin() ; 
		up.erase(up.find(newlow)) ; 
		low.insert(newlow) ; 
		sl += newlow ; su -= newlow ; 
	}

}

int med(){ return (k&1 ? *low.rbegin() : 0) ; }

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

	low.insert(v[1]) ; sl += v[1] ; 
    for(int i = 2 ; i <= k ; i++) ins(v[i]) ; 

    cout << su - sl + med() << " " ; 

    for(int i = k + 1 ; i <= n ; i++){
    	
    	if(k == 1) ins(v[i]), ren(v[i-k]) ; 
		else ren(v[i-k]), ins(v[i])  ; 
		cout << su - sl + med() << " " ; 
    }

    cout << "\n" ; 

}

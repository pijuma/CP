#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, q, v[maxn], ans[maxn], bit[maxn] ; 
vector<pair<int,int>> queryy[maxn] ; 

struct BIT{

	void upd(int pos){ for(; pos < maxn ; pos += pos&-pos) bit[pos]++ ; }

	int que(int pos){
		int tot = 0 ;
		for(; pos > 0 ; pos -= pos&-pos) tot += bit[pos] ;  
		return tot ; 
	}

	int query(int l, int r){ return que(r) - que(l-1) ; }

} Bit ; 

int main(){

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= q ; i++){
		int l, r ; 
		cin >> l >> r ; 
		queryy[r].push_back({l, i}) ; 
	}

	vector<int> st ; 

	for(int i = 1 ; i <= n ; i++){
		while(!st.empty() && v[st.back()] > v[i]) st.pop_back() ; 
		if(!st.empty() && v[st.back()] == v[i]){
			Bit.upd(st.back()) ; st.back() = i ; 
		}
		else st.push_back(i) ; 
		for(auto a : queryy[i]) ans[a.second] = i - a.first + 1 - Bit.query(a.first, i+1) ; 
	}

    for(int i = 1 ; i <= q ; i++) cout << ans[i] << "\n" ;  

}

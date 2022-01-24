#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 205 ; 

int n ; 
char s[maxn], pal[maxn] ; 

void solve(char c){

	vector<int> ans ; 

	for(int i = 0 ; i < n ; i++) pal[i] = s[i] ; 

	for(int i = 0 ; i < n - 1 ; i++){
		if(pal[i] == c) continue ; 
		pal[i] = c ; 
		ans.push_back(i) ;  
		if(pal[i+1] == 'B') pal[i+1] = 'W' ;
		else pal[i+1] = 'B' ;
	}

	if(pal[n-1] != c) return ; 

	cout << ans.size() << "\n" ; 

	for(int i = 0 ; i < (int)ans.size() ; i++) cout << ans[i] + 1 << " " ; 
    exit(0) ;

}

int main(){


	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 0 ; i < n ; i++) cin >> s[i] ;  

	solve('B') ; solve('W') ; 

	cout << "-1\n" ; 

}

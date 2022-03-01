#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 28*25005 ; 

int n, fim[maxn], trie[maxn][28], qtd_pal, mx[maxn], ct ; 
string s ; 
vector<char> ans ; 

void add(string s){

	int root = 0 ; 

	for(int i = 0 ; i < s.size() ; i++){
		if(!trie[root][s[i]-'a']) trie[root][s[i]-'a'] = ++ct ; 
		root = trie[root][s[i]-'a'] ; 
	}

	fim[root] = 1 ; 

}

void dfs_alt(int v, int p){

	mx[v] = 1 ; 

	for(char i = 'a' ; i <= 'z' ; i++){
		if(!trie[v][i-'a'] || trie[v][i-'a'] == p) continue ; 
		dfs_alt(trie[v][i-'a'], v) ; 
		mx[v] = max(mx[v], mx[trie[v][i-'a']] + 1) ;  
	}

}

void dfs(int v, int p){

	if(fim[v]){
		ans.push_back('P') ;
		qtd_pal += fim[v] ;  
	}

	int mxx = -1 ; char ind = 0 ;

	for(char i = 'a' ; i <= 'z' ; i++){
		if(!trie[v][i-'a'] || trie[v][i-'a'] == p) continue ; 
		if(mxx < mx[trie[v][i-'a']]){
			mxx = mx[trie[v][i-'a']] ; ind = i ; 
		}
	} 

	for(char i = 'a' ; i <= 'z' ; i++){
		if(!trie[v][i-'a'] || trie[v][i-'a'] == p || i == ind) continue ; 
		ans.push_back(i) ; 
		dfs(trie[v][i-'a'], v) ; 
 	}

 	if(mxx != -1 && trie[v][ind-'a']){
 		ans.push_back(ind) ; 
 		dfs(trie[v][ind-'a'], v) ; 
 	
}
	if(qtd_pal != n) ans.push_back('-') ; 

}

// void dfs_view(int v, int p){

// 	for(char i = 'a' ; i <= 'z' ; i++){
// 		if(!trie[v][i-'a'] || trie[v][i-'a'] == p) continue ; 
// 		cout << trie[v][i-'a'] << " " << i << "\n" ; 
// 		dfs_view(trie[v][i-'a'] , v) ;
// 	} 

// }

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> s ; 
		add(s) ; 
	}

	dfs_alt(0, 0) ; 

	// dfs_view(0, 0) ; 

	dfs(0, 0) ; 

	// for(int i = 0 ; i <= 8 ; i++) cout << mx[i] << " " ; 

	// cout << "\n" ; 

	cout << ans.size() << "\n" ; 

	for(auto a : ans) cout << a << "\n" ; 

}

#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int t, S, d, vis[10], g[5][5] ;
vector<string> resp ; 
string s ; 
map<int, char> mp ; 


bool valid(int i, int j){ return i > 0 && j > 0 && i <= 4 && j <= 3 && g[i][j] != -1 ; }

int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1} ; 
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1} ;

int get_num(string ss){

	int v = 1, num = 0 ; 

	reverse(ss.begin(), ss.end()) ; 

	for(int i = 0 ; i < ss.size() ; i++){
		num += ((ss[i]-'0')*v) ; 
		v *= 10 ; 
	}

	reverse(ss.begin(), ss.end()) ; 

	return num ; 

}

void solve(int i, int j, int sum){

	if(sum < 0) return ; 

	int t = 0 ; 
	string att = "" ; 
	int difs = 0 ;

	for(int l = 0 ; l < s.size() ; l++){
		if(s[l] == '*'){
			if(att.size() != d) difs++ ; 
			att = "" ; 
		}
		else att += s[l] ; 
	}

	t = att.size() ; 

	if(sum == 0 && t <= d && difs <= 1){
		// cout << s << "\n" ;
		resp.push_back(s) ; 
		return ; 
	}

	if(sum == 0) return ; 

	int val = get_num(att) ; 

	if(t == d || sum - val == 0){
		s += '*' ;
		for(int k = 0 ; k < 8 ; k++){
			int ni = i + dx[k], nj = j + dy[k] ; 
			if(!valid(ni, nj) || vis[g[ni][nj]]) continue ;
			s += mp[g[ni][nj]] ;  vis[g[ni][nj]] = 1 ; 
			if(sum - val == 0) s.pop_back(), s.pop_back() ; 
			if(g[ni][nj] == 0 && sum - val == 0){
				s += '*' ; 
				s += mp[g[ni][nj]] ; 
				solve(ni, nj, sum - val) ;
				s.pop_back() ; s.pop_back() ; 
			}
			solve(ni, nj, sum - val) ;
			vis[g[ni][nj]] = 0 ; 
			if(sum - val == 0) s += '*' ; 
			if(sum - val) s.pop_back() ;  
		}
		s.pop_back() ; 
	}

	if(sum - val == 0){
		solve(i, j, sum - val) ; 
	}

	for(int k = 0 ; k < 8 ; k++){
		int ni = i + dx[k], nj = j + dy[k] ; 
		if(!valid(ni, nj) || vis[g[ni][nj]]) continue ; 
		vis[g[ni][nj]] = 1 ; 
		if(t != d){
			s += mp[g[ni][nj]] ;
			solve(ni, nj, sum) ; 
			s.pop_back() ; 
		}
		vis[g[ni][nj]] = 0 ; 
	}

	return ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	int v = 0 ; 

	for(int i = 1 ; i <= 4 ; i++){
		for(int j = 1 ; j <= 3 ; j++){
			g[i][j] = ++v ; 
		}
	}

	g[4][1] = -1, g[4][2] = 0, g[4][3] = -1 ; 

	for(char i = '0' ; i <= '9' ; i++) mp[i-'0'] = i ;  

	while(true){
		
		resp.clear() ; 

		cin >> S >> d ; 
		if(S == -1 && d == -1) return 0 ; 
		
		for(int i = 1 ; i <= 4 ; i++){
			for(int j = 1 ; j <= 3 ; j++){
				if(g[i][j] == -1 || g[i][j] > S) continue ; 
				memset(vis, 0, sizeof vis) ; 
				s = '*' ; s += mp[g[i][j]] ; 
				vis[g[i][j]] = 1 ; 
				solve(i, j, S) ; 
			}
		}

		sort(resp.begin(), resp.end()) ; 
		resp.erase(unique(resp.begin(), resp.end()), resp.end()) ; 

		cout << "#" << ++t << "\n" ; 

		if(resp.size() == 0) cout << "impossivel\n" ; 
		else{
		  	for(int i = 0 ; i < resp.size() ; i++){
		    	vector<string> k ; 
		    	string at = "" ; 
		    	for(int j = 1 ; j < resp[i].size() ; j++){
		     		if(resp[i][j] == '*') cout << " " ;
		    		else cout << resp[i][j] ; 
		    	}
	    		cout << "\n" ; 
	    	}
		}

	}

}

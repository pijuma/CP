#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 3e3 + 5 ; 

int dp[maxn][maxn] ; 
string s, t ; 

int main(){

	cin >> s >> t ; 
	
	s = " " + s, t = " " + t ; 

	for(int i = 0 ; i < s.size() ; i++){
		
		for(int j = 0 ; j < t.size() ; j++){

			if(!i || !j) dp[i][j] = 0 ; 
			else if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1 ; 
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;

		}

	}

	string ans = "" ;  
	int curx = s.size() - 1, cury = t.size() - 1 ; 

	while(curx && cury){

		if(s[curx] == t[cury]){
			ans = ans + s[curx] ; 
			curx--, cury-- ; 
		} 
		else{
			if(dp[curx][cury] == dp[curx - 1][cury]) curx-- ; 
			else cury-- ; 
		}

	}

	reverse(ans.begin(), ans.end()) ; 

	cout << ans << "\n" ; 

}

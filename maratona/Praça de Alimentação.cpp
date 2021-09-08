#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

string s ; 
int n ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	while(true){
		
		cin >> n ; 
		
		if(!n) return 0 ; 
		char c ; 
		vector<pair<int,int>> v ; 

		int rem = n/2 ; 

		for(int i = 1 ; i <= n ; i++){
		    cin >> s >> c ; 
		    int h = 10*(s[0] - '0') + (s[1] - '0') ; 
		    int m = 10*(s[3] - '0') + (s[4] - '0') ; 
		    int ss = 10*(s[6] - '0') + (s[7] - '0') ;
		    if(c == 'E') rem-- ; 
		    v.push_back({h*3600 + m*60 + ss, (c == '?' ? 0 : (c == 'E' ? 1 : -1))}) ; 
		}

		sort(v.begin(), v.end()) ; 

		int ans = 0, at = 0 ; 

		for(int i = 0 ; i < n ; i++){
			if(v[i].second != 0) at += v[i].second ; 
			else{
				if(rem > 0) at++, rem-- ; 
				else at-- ; 
			}
			ans = max(ans, at) ; 
		}

		cout << ans << "\n" ; 
	}

}

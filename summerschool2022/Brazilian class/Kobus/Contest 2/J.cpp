#include<bits/stdc++.h>
using namespace std ; 

string ok[4] = {"00", "25", "50", "75"} ; 

int t ; 
string s ; 

int main(){

	cin >> t ; 

	while(t--){
		
		cin >> s ; 

		int ans = s.size() ; 

		for(int i = 0 ; i < 4 ; i++){
			int p1 = 1 ; 
			for(int j = s.size() - 1 ; j >= 0 ; j--){
				if(s[j] == ok[i][p1]) p1-- ; 
				if(p1 == -1) ans = min(ans, (int)s.size() - j - 2) ; 
			}
		}

		cout << ans << "\n" ; 

	}

}

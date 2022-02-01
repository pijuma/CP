#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e6 + 5 ; 

int n, t, qtd ;
vector<int> ans ;  
string A[maxn], B[maxn] ; 
map<string, int> mp ; 

int main(){


	cin >> t ; 

	while(t--){

		cin >> n ; 
		
		ans.clear() ; 

		for(int i = 1 ; i <= n ; i++) cin >> A[i] ; 
		for(int i = 1 ; i <= n ; i++) cin >> B[i] ; 

		int len = 0 ; qtd = 0 ; 

		for(int i = 1 ; i <= n ; i++){

			len++ ; 

			if(!mp[A[i]]){
				mp[A[i]]++ ;  
			    qtd++ ; 
			}

			else{
				mp[A[i]]-- ; 
				qtd-- ; 
			}

			if(qtd == 1 && mp[B[i]] == 1){
				ans.push_back(len) ; 
				len = 0 ; 
				mp[B[i]]-- ; 
				qtd = 0 ; 
			}
			
			else if(!mp[B[i]]) {
				mp[B[i]]++ ; 
				qtd++ ; 
			}

			else{
				mp[B[i]]-- ; 
				qtd-- ; 
			}

			// cout << qtd << " " << len << "\n" ; 

		}

		for(auto a : ans) cout << a << " " ; 
		cout << "\n" ; 

	}

}

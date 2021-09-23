    #include<bits/stdc++.h>
    #define int long long
    using namespace std ; 
     
    int a, b, dp[22][2][11][11] ; 
    vector<int> num ; 
     
    int solve(int pos, bool flag, int p1, int p2){
     
    	if(pos == num.size()) return 1 ; 
    	if(dp[pos][flag][p1][p2] != -1) return dp[pos][flag][p1][p2] ; 
     
    	int tot = 0 ; 
     
    	if(flag){ // garantido 
    		for(int i = 0 ; i < 10 ; i++){
    			if(i == p1 || i == p2) continue ;
    			tot += solve(pos+1, flag, p2, i) ; 
    		}
    	}
     
    	else{
    		for(int i = 0 ; i <= num[pos] ; i++){
    			if(i == p1 || i == p2) continue ; 
    			tot += solve(pos + 1, (i != num[pos]), p2, i) ; 
    		}
    	}
     
    	return dp[pos][flag][p1][p2] = tot ; 
     
    }
     
    int calc(int a){
     
    	if(a < 0) return 0 ; 
    	if(a == 0) return 1 ; 
    	num.clear() ; 
    	while(a){
    		num.push_back(a%10) ; a /= 10 ;
    	}
     
    	reverse(num.begin(), num.end()) ; 
     
    	memset(dp, -1, sizeof dp) ; 
     
    	int ans = 0 ; 
    	for(int i = 0 ; i < num.size() ; i++) ans += solve(i, i != 0, (i == num.size() - 1 ? 10 : 0), 10) ; 
    	return ans ; 
     
    }
     
    int32_t main(){
     
    	cin >> a >> b ; 
    	cout << calc(b) - calc(a-1) << "\n" ; 
     
    }

    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 2550 ; 
    int n, ans, m[maxn][8] ; 
    vector<int> sum2, sum1 ; 
     
    int main(){
    	
    	cin >> n ; 
    	
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = 1 ; j <= 4 ; j++){
    			cin >> m[i][j] ;  
    		}
    	}
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			sum1.push_back(m[i][1] + m[j][2]) ; 
    			sum2.push_back(m[i][3] + m[j][4]) ; 
    		}
    	}
     
    	sort(sum2.begin(), sum2.end()) ; 
     
    	for(int i = 0 ; i < sum1.size() ; i++){
    		int v = lower_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin() ; 
    		int s = upper_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin() ; 
    		ans += abs(v-s) ; 
    	}
     
    	cout << ans << "\n"; 
     
    } 

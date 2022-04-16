    #include<bits/stdc++.h>
    using namespace std ; 
     
    int n, t, vis[15] ; 
     
    int32_t main(){
     
    	cin >> t ; 
     
    	while(t--){
     
    		cin >> n ; 
     
    		memset(vis, 0, sizeof vis) ; 
    		
       		for(int i = 1 ; i < n ; i++){
        		int x ; 
        		cin >> x ; 
        		vis[x] = 1 ; 
        	}
     
        	for(int i = 1 ; i <= n ; i++){
        		if(!vis[i]){
        			cout << i << "\n" ; 
        			break ; 
        		} 
        	}
    	}
     
    }

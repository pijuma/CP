    #include<bits/stdc++.h>
    using namespace std ; 
     
    // p meninos e p meninas 
    // tds meninas sao amgs e tds meninos 
    // b amg de g 
    // fixa as meninas que estarão no grupo 
    // e retira os meninos que nao podem e os meninos que podem 
     
    int p, n, t, amg[22], ran[22] ; 
     
    int main(){
     
    	cin >> t ; 
     
    	while(t--){
    		
    		cin >> p >> n ; 
     
    		memset(amg, 0, sizeof amg) ; memset(ran, 0, sizeof ran) ; 
     
    		for(int i = 1 ; i <= n ; i++){
    			int b, g ; 
    			cin >> b >> g ; b--, g-- ; 
    			amg[g] |= (1<<b) ;
    		}
     
    		for(int i = 0 ; i < p ; i++){
    			ran[i] = (1<<p) - 1 ; 
    			ran[i] = ran[i]^amg[i] ; 
    		}
     
    		int cant = 0 ; 
    		int ans = 0 ; 
     
    		for(int mask = 0 ; mask < (1<<p) ; mask++){ // quais gurias vou usar
    			int gurias = 0 ; 
    			int cant = 0 ; 
    			for(int i = 0 ; i < p ; i++){
    				if(!(mask&(1<<i))) continue ; // n ta no grupo 
    				cant = ran[i]|cant ; 
    				gurias++ ; 
    			}
    			int ct = 0 ; 
    			for(int i = 0 ; i < p ; i++){
    				if(!(cant&(1<<i))) continue ; 
    				ct++ ; 
    			}
    			// cout << mask << " " << gurias << " " << ct << "\n" ; 
    			ans = max(ans, p - ct + gurias) ; 
    		}
     
    		cout << ans << "\n" ; 
     
    	}
     
    }

    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    // começa em x 
    // usou n digitos 
     
    int n, x, t ; 
     
    int exp(int a, int b){
     
    	int ans = 1 ; 
     
    	while(b){
    		if(b&1) ans = (ans*a) ; 
    		a = (a*a) ; 
    		b >>= 1 ; 
    	}
     
    	return ans ; 
     
    }
     
    int32_t main(){
     
    	cin >> t ; 
     
    	while(t--){
    		
    		cin >> x >> n ; 
     
    		int ans = 0, sum = 0 ; 
    		int last = n ; 
     
    		for(int i = 1 ; i <= 16 ; i++){
    			string s = "" ; int qtd = i ;  
    			int numb = 0 ; 
    			for(int j = 0 ; j < qtd ; j++)  numb += exp(10, j)*9 ;  
    			if(n > numb) continue ;
    			int qtdlas = i*(numb - last + 1) ; 
    			// cout << x << " " << numb << " " << last << " " << i << " " << qtdlas << "\n" ;
    			if(qtdlas <= x) x -= qtdlas ; 
    			else{
    				if(x%i) ans = -1 ; 
    				else ans = (last - 1 + x/i) - n + 1 ;
    				break ;
    			}
    			last = numb + 1 ; 
    		}
     
    		cout << ans << "\n" ; 
     
    	}
     
    }


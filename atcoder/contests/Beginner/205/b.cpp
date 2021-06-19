    #include<bits/stdc++.h>
    using namespace std ; 
     
    int n ; 
    set<int> v ; 
     
    int main(){
     
    	cin >> n ; 
     
    	for(int i = 1, a; i <= n ; i++){
    		cin >> a ; 
    		v.insert(a) ; 
    	} 
     
    	if(v.size() == n) cout << "Yes\n" ; 
    	else cout << "No\n" ; 
    	
    }

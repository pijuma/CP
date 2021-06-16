    #include<bits/stdc++.h>
    using namespace std ; 
     
    int a, b, c ; 
     
    int main(){
     
    	cin >> a >> b >> c ; 
     
    	if(a == b && b != c) cout << c << "\n" ;
    	else if(a == c && b != c) cout << b << "\n" ; 
    	else if(b == c && b != a) cout << a << "\n" ; 
    	else if(a == b && b == c) cout << a << "\n" ; 
    	else cout << "0\n" ; 
     
    }

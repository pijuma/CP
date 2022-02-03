#include<bits/stdc++.h>
using namespace std ; 

long long n, ans ;

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; n-- ; 

	for(long long i = 1 ; i <= n ; i <<= 1) ans += (((n-i)/(i<<1)) + 1)*i ; 

	cout << ans ; 

} 

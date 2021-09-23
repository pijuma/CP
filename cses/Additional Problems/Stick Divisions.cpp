#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
int x, n, v, ans ; 
priority_queue<int, vector<int>, greater<int>> fila ;
 
int32_t main(){
 
	cin >> x >> n ; 
 
	for(int i = 1 ; i <= n ; i++){
		int v ; 
		cin >> v ; 
		fila.push(v) ; 
	}
 
	while(fila.size() >= 2){
		int a = fila.top() ; fila.pop() ; 
		int b = fila.top() ; fila.pop() ; 
		ans += (a+b) ; 
		fila.push(a+b) ; 
	}
 
	cout << ans << "\n" ;
 
}

#include<bits/stdc++.h>
using namespace std ; 
 
int n ; 
 
int main(){
 
	cin >> n ; 
 
	int f1 = 2 ; 
 
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
 
	for(int i = 1 ; i <= n ; i++) fila.push({0, i}) ; 
 
	while(!fila.empty()){ // pega de 2 em 2 
		pair<int,int> a = fila.top() ; 
		fila.pop() ; 
		fila.push({a.first + 1, a.second}) ; 
		a = fila.top() ; 
		fila.pop() ; 
		cout << a.second << " " ; 
	}
 
	cout << "\n" ; 
 
}

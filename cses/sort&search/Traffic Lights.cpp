#include<bits/stdc++.h>
using namespace std ; 
 
int n, x, v ; 
set<int> pos ; 
set<pair<int,pair<int,int>>> ans ; 
 
//upper -> 1o maior 
 
int main(){
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	cin >> x >> n ; 
 
	pos.insert(0), pos.insert(x) ; //insere as posições no começo 
	ans.insert({x, {0, x}}) ; //dist p mais prox e o intervalo 
 
	for(int i = 0 ; i < n ; i++){
 
		cin >> v ; 
 
		auto it = pos.upper_bound(v) ; 
 
		int a = (*it) ; //1o dps 
		it-- ; 
		int b = (*it) ; //1o antes 
 
		pos.insert(v) ; 
		ans.erase({a - b, {b, a}}) ; // apagar o intervalo anterior 
		ans.insert({a - v, {v, a}}) ; // coloca os novos 
		ans.insert({v - b, {b, v}}) ; 
 
		cout << (*ans.rbegin()).first << ' ' ; 
 
	}
 
	cout << "\n" ; 
 
}

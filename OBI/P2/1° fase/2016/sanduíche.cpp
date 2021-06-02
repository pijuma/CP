#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e6 + 5 ; 

int n, d, qtd  ;
map<int,int> v ;
int main(){

	cin >> n >> d ; 

	for(int i = 0 ; i < n ; i++) cin >> v[i], v[n+i] = v[i] ;
	int sum = 0; 
	for(int r = -1, l = 0 ; l < n ; l++){
		while(r + 1 < l + n && sum < d)sum += v[++r] ; 
		if(sum == d) qtd++ ; 
		sum -= v[l] ; 
	}

	cout << qtd << "\n" ; 
}

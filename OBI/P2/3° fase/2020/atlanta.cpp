#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 1 ; //1e3*1e3 = 1e6 - max 
int a, b ; 

int main(){

	cin >> a >> b ; 

	for(int i = 2 ; i < maxn ; i++){
		for(int j = i ; j > 1 ; j--){
			if(a+b == i*j && a == 2*i + 2*j - 4){
				cout << j << " " << i << "\n" ; 
				return 0 ; 
			}
		} 
	}

	cout << "-1 -1\n" ; 
}

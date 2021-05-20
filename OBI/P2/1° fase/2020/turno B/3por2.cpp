#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 100005 ; 

int n, p[maxn], sum ;

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i], sum += p[i] ; 

	sort(p + 1, p + 1 + n) ; 
    
  int ini = n%3 ; 

  for(int i = ini + 1 ; i <= n ; i += 3) sum -= p[i] ; 

  cout << sum << "\n" ; 

}

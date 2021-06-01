#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

//nlogn 

const int maxn = 1e6 + 5 ; 

int n, k, v[maxn], p[maxn] ; 

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

	// dif entre o upper e o lower bound 
  // queremos saber qts são iguais ent fznd isso pegamos 
  // o 1o maior menos o 1o q eh maior ou igual 
	// fazemos isso na soma parcial -> fazemos de i até n 

	for(int i = 1 ; i <= n ; i++) p[i] = p[i-1] + v[i] ;

	long long ans = 0 ; 
    
    for(int i = 1 ; i <= n ; i++){
    	ans += upper_bound(p + i, p + n + 1, p[i-1] + k) - lower_bound(p + i, p + n + 1, p[i-1] + k) ; 
    	// se eu começar no i até qual eu pss ir? (qts opcões tenho para q a soma seja k)
    }

    cout << ans << "\n" ; 

}

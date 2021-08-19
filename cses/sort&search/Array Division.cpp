#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

// n inteiros 
// queremos dividir em k subarrays 
// em q a maior soma de um subarray é a menor possivel 
// qual a maior soma ? 

const int maxn = 2e5 + 5 ; 

int n, k, v[maxn], total ; 

bool check(int sum){

	int divs = 1 ; 
	int sum_atual = 0 ; 

	for(int i = 1 ; i <= n ; i++){

		if(v[i] > sum) return false ; 

		if(sum_atual + v[i] <= sum) sum_atual += v[i] ;
		else{
			divs++ ; 
			sum_atual = v[i] ; 
		}

	}

	return divs <= k ; 

}

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i], total += v[i] ; 
    
    int ini = 1, fim = total + 1, mid, best ; 
    
    while(ini <= fim){

    	mid = (ini + fim)>>1 ; 

    	if(check(mid)) best = mid, fim = mid - 1 ; 
    	else ini = mid + 1 ; 

    }

    cout << best << "\n" ; 

}

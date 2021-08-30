#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 15 ; 
const int mod = 1e9 + 7 ; 

int r, g, h, dp[3][maxn] ; 

int pa(int x){return (x*(x+1)/2) ; }

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	// qual hmax ? 

	cin >> r >> g ; 
	while(pa(h+1) <= r + g) h++ ;
	// cout << h << "\n" ; 
	for(int i = 0 ; i <= r ; i++) dp[(h+1)%2][i] = 1 ; 

	for(int i = h ; i > 0 ; i--){
		
		for(int R = 0 ; R <= r ; R++){ // usei R verm até agr - resto verde 
			int green = g - (pa(i-1) - (r - R)) ;  
			dp[(i%2)][R] = 0 ; 
			if(R >= i) dp[i%2][R] = (dp[i%2][R] + dp[(i+1)%2][R - i])%mod ; // pss colocar o ith vermelho passando p prox nivel c menos verm
			if(green >= i) dp[i%2][R] = (dp[i%2][R] + dp[(i+1)%2][R])%mod ; // ith verde passando p prox nivel com a msm qtd
		}

	}

	cout << dp[1][r] << "\n" ; 

}

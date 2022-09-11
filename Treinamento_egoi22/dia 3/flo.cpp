// https://dmoj.ca/problem/ioi99p1
// v vasos de 1 a v
// queremos manter a ordem relativa dos tipos de plantas
// queremos ocupar os vasos de forma a maximizar a soma total 
// um vaso p cada planta 
// dp[i][j] - to no vaso i na planta j 
// se eu passar colocando a planta atual eu passo p i+1, j+1 
// ou posso n colocar passo p i+1, j 
// qro maximizar 
#include<bits/stdc++.h>
using namespace std ; 

const int inf = 1e7 + 5 ; 
const int maxn = 110 ;

int f, v, calc[maxn][maxn], m[maxn][maxn], dp[maxn][maxn] ; 
vector<int> take ; 

int solve(int i, int j){
	if(i > f) return 0 ; 
	if(j > v) return -inf ; 
	if(calc[i][j]) return dp[i][j] ;
	int a =  solve(i+1, j+1), b = solve(i, j+1) ;
	if(a != -inf) a += m[i][j] ; 
	calc[i][j] = 1 ; 
	return dp[i][j] = max(a, b) ;  
}

int main(){

	cin >> f >> v ; 

	for(int i = 1 ; i <= f ; i++){
		for(int j = 1 ; j <= v ; j++){
			cin >> m[i][j] ; 
		}
	}

	cout << solve(1, 1) << "\n" ;

	int tipo = 1, vaso = 1 ; 

	vector<int> take ; 

	while(1){
		if(tipo > f || vaso > v) break ; 
		if(dp[tipo][vaso] == dp[tipo][vaso+1]) vaso++ ; 
		else{
			take.push_back(vaso) ; 
			tipo++, vaso++ ; 
		}
	}

	// reverse(take.begin(), take.end()) ; 

	for(auto a : take) cout << a << " " ; 
	cout << "\n" ; 

	// for(int i = 1 ; i <= f ; i++){
	// 	for(int j = 1 ; j <= v ; j++){
	// 		cout << dp[i][j] << " " ; 
	// 	}
	// 	cout << "\n" ; 
	// }

}

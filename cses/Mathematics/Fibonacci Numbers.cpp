#include<bits/stdc++.h>
using namespace std ; 
 
const int mod =  1e9 + 7 ; 
 
long long n ; 
 
struct Mat{
 
	long long v[2][2] ;
 
	Mat& operator = (int mat[2][2]){
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j < 2 ; j++){
				v[i][j] = mat[i][j] ; 
			}
		}
		return *this ; 
	}
 
	Mat(){
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j < 2 ; j++){
				v[i][j] = 0 ; 
			}
		}
	}
 
	void id(){
		for(int i = 0 ; i < 2 ; i++) v[i][i] = 1 ; 
	}
 
} ;
 
Mat mult(Mat a, Mat b){
	
	Mat ans ; 
	
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 2 ; j++){
			for(int k = 0 ; k < 2 ; k++){
				ans.v[i][j] = (ans.v[i][j] + (1LL*a.v[i][k]*b.v[k][j])%mod)%mod ; 
			}
		}
	}
	
	return ans ; 
 
}
 
Mat expo(Mat a, long long b){
	
	Mat ans ; 
	ans.id() ; 
	
	while(b){
		if(b&1) ans = mult(ans, a) ; 
		a = mult(a, a) ; 
		b >>= 1 ; 
	}
 
	return ans ; 
 
}
 
int main(){
 
	cin >> n ; 
 
	if(n <= 1){
		cout << n << "\n" ; 
		return 0 ; 
	} 
 
	Mat ans, base, aux ; 
 
	int a[2][2] = {1, 1, 1, 0} ; 
	aux = a ; 
 
	int b[2][2] = {1, 0, 0, 0} ;
	base = b ; 
 
	ans = mult(expo(aux, n-1), base) ; 
 
	cout << ans.v[0][0] << "\n" ; 
 
}

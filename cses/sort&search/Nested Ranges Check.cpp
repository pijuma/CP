#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, x, y ; 
pair<int,int> pto[maxn], resp[maxn] ; 
map<pair<int,int>, int> contem, cont ; 
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++){
		cin >> pto[i].first >> pto[i].second ;
		pto[i].second *= -1 ; 
		resp[i] = pto[i] ; 
	} 
 
	sort(pto + 1, pto + 1 + n) ;
    
    int mny = (int) (1e9 + 5) ;
 
    for(int i = n ; i > 0 ; i--){
    	contem[pto[i]] = (-pto[i].second >= mny) ; 
    	mny = min(mny, -pto[i].second) ; 
    }
 
    mny = 0 ; 
 
    for(int i = 1 ; i <= n ; i++){
    	cont[pto[i]] = (-pto[i].second <= mny) ; 
    	mny = max(mny, -pto[i].second) ; 
    }
 
    for(int i = 1 ; i <= n ; i++) cout << contem[resp[i]] << " " ; 
    cout << "\n" ; 
    for(int i = 1 ; i <= n ; i++) cout << cont[resp[i]] << " " ;
    cout << "\n" ; 
 
}

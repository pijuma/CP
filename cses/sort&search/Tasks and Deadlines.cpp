#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
long long resp, v[maxn], n, x ; 
 
// 1o -> deadline - time[1]
// 2o -> deadline - time[1] - time[2] 
// p maximizar as tarefas de maior duração devem ser feitas dps p "subtrair menos"
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) {
		cin >> v[i] >> x ; 
		resp += x ; 
	}
 
	sort(v + 1, v + 1 + n) ; 
    
    for(int i = 1 ; i <= n ; i++) resp -= ((n-i+1)*v[i]) ; 
 
    cout << resp << "\n" ; 
 
}

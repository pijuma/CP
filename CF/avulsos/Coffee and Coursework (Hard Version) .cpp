    #include<bits/stdc++.h>
    #define int long long
    using namespace std ; 
     
    // ai -> copo i tem ai cafeina 
    // qlqr ordem 
    // bebe k copos no dia 
    // cada copo da energia max(0, aik - k + 1)
     
    const int maxn = 2e5 + 5 ; 
     
    int n, v[maxn], m ; 
     
    bool ok(int i){
    	int s = 0 ; 
       	for(int j = 1 ; j <= n ; j++) s += max(0LL, v[j] - (j - 1)/i) ; //dx os maiores smp como 1o do bloco ou + perto disso
       	// "ordem decrescente" em cada bloco 
       	// eu sou kth cafe do dia (j-1)/i
        if(s >= m) return 1 ; 
        return 0 ; 
    }
     
    int32_t main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n >> m ; 
     
    	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
     
    	sort(v + 1, v + 1 + n), reverse(v + 1, v + 1 + n) ; 
        
        int ini = 1, fim = n, mid, best = -1 ; 
     
        while(ini <= fim){
        	mid = (ini + fim)/2 ; 
        	if(ok(mid)) best = mid, fim = mid - 1 ; 
        	else ini = mid + 1 ; 
        }
     
        cout << best << "\n" ; 
     
    }

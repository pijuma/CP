#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int inf = 1e18 ; 
int n, b ; 

int32_t main(){

	cin >> n >> b ; 

	int a1 = 4*n - 4 ; 
	
	int ini = 1, fim = n/2, mid, best = 0 ; 
	int r = -8 ;

	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		int an = (a1 + (r*(mid-1))) ; 
		int sn = (a1 + an)*mid ; 
		sn >>= 1 ;
		if(sn < b) best = mid, ini = mid + 1 ; 
		else fim = mid - 1 ; 
	}

	int lado = (n-(best<<1));
	int an = a1 + (-8*(best-1));
	int sn = ((a1 + an)*best)>>1;

	if (sn + lado >= b) cout << best+1 << ' ' << best + (b - sn) << endl;
	else if (sn + (2*lado) - 1 >= b) cout << best + 1 + (b - (sn + lado)) << ' ' << n-best << endl;
	else if (sn + (lado*3) - 2 >= b) cout << n-best << ' ' << n - (best + b - (sn + (2*lado) - 1)) << endl; 
	else cout << n - (best+b-(sn + (lado*3) - 2)) << ' ' << best+1 << endl;

}

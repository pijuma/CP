#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 120 ;
const int inf = 1e18 ; 

int t, w, p, x[maxn], ct, y[maxn], z[maxn] ;
double dist[maxn][maxn] ;  
map<string, int> mp ;
string planet[maxn] ; 

double make_dist(int i, int j){

	double dx = abs(x[j] - x[i]) ;
	double  dy = abs(y[i] - y[j]) ; 
	double  dz = abs(z[i] - z[j]) ; 

	dx *= dx, dy *= dy, dz *= dz ; 

	double ans = sqrt(dx+dy+dz) ; 

	return ans ; 
}

int prox(double ans){

	int first = floor(ans), second = ceil(ans) ; 

	if(abs((double)ans - first) <= abs((double)second - ans)) return first ; 
	return second ;

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> t ; 

	while(t--){

		mp.clear() ; 

		cin >> p ; 

		for(int i = 1 ; i <= p ; i++){
			cin >> planet[i] >> x[i] >> y[i] >> z[i] ; 
			mp[planet[i]] = i ; 
		}

		cin >> w ; 

		for(int i = 1 ; i <= p ; i++){
			for(int j = 1 ; j <= p ; j++){
				dist[i][j] = inf*1.00 ; 
			}
		}

		for(int i = 1 ; i <= p ; i++){
			for(int j = 1 ; j <= p ; j++){
				dist[i][j] = make_dist(i, j) ; 
			}
		}

		for(int i = 1 ; i <= w ; i++){
			string p1, p2 ; 
			cin >> p1 >> p2 ; 
			dist[mp[p1]][mp[p2]] = 0 ; 
		}

		// for(int i = 1 ; i <= p ; i++){
		// 	for(int j = 1 ; j <= p ; j++){
		// 		cout << dist[i][j] << " " ; 
		// 	}
		// 	cout << "\n" ; 
		// }

		for(int k = 1 ; k <= p ; k++){
			for(int i = 1 ; i <= p ; i++){
				for(int j = 1 ; j <= p ; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) ;
				}
			}
		}

		// for(int i = 1 ; i <= p ; i++){
		// 	for(int j = 1 ; j <= p ; j++){
		// 		cout << dist[i][j] << " " ; 
		// 	}
		// 	cout << "\n" ; 
		// }

		int q ; 

		cin >> q ; 

		cout << "Case " << ++ct << ":\n" ; 

		while(q--){
			string p1, p2 ; 
			cin >> p1 >> p2 ; 
			cout << "The distance from " << p1 << " to "<< p2 << " is " << prox(dist[mp[p1]][mp[p2]]) << " parsecs.\n" ; 
			// cout << dist[mp[p1]][mp[p2]] << "\n" ; 
		}

	}

}

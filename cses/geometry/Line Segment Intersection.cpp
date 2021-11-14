#include<bits/stdc++.h>
#define int long long
#define ll long long 
using namespace std ; 
 
struct Point{
 
	ll x, y ; 

	Point operator -(Point a){return {(x-a.x), (y-a.y)} ; }

} ; 

int cross(Point a, Point b){return (a.x*b.y)-(a.y*b.x) ; }
int dot(Point a, Point b){ return (a.x*b.x)+(a.y*b.y) ; }

Point p[3] ; 

void solve(){

	for(int i = 1 ; i <= 4 ; i++) cin >> p[i].x >> p[i].y ;

	if(cross(p[2]-p[1], p[4] - p[3]) == 0){
		if(cross(p[2] - p[1], p[3] - p[1]) != 0){
			cout << "NO\n" ; 
			return ; 
		} 
		for(int i = 1 ; i <= 2 ; i++){
			if(max(p[1].x, p[2].x) < min(p[3].x, p[4].x) || max(p[1].y, p[2].y) < min(p[3].y, p[4].y)){
				cout << "NO\n" ; 
				return ; 
			}
			swap(p[1], p[3]), swap(p[2], p[4]) ; 
		}
	}

	for(int i = 1 ; i <= 2 ; i++){

		int sg1 = cross(p[2] - p[1], p[3]-p[1]) ; 
        int sg2 = cross(p[2] - p[1], p[4] - p[1]) ; 
 
    	if((sg1 > 0 && sg2 > 0) || (sg1 < 0 && sg2 < 0)){
    		cout << "NO\n" ;
    		return ; 
    	} 

    	swap(p[1], p[3]), swap(p[2], p[4]) ; 

	} 

	cout << "YES\n" ; 

}

int32_t main(){
	
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	int t ; 
 
	cin >> t ; 
 
	while(t--) solve() ; 
 
}

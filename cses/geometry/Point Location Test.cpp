#include<bits/stdc++.h>
#define ll long long 
using namespace std ; 
 
struct Point{
 
	ll x, y ; 
 
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}
 
	ll operator % (Point a) const{ // cross -> sen
		return (x*a.y) - (y*a.x) ; 
	}
 
	ll operator * (Point a) const{
		return (x*a.x) + (y*a.y) ; 
	}
 
	Point operator - (Point a) const{
		return Point(x-a.x, y-a.y) ;
	}
} ; 
 
Point p[3] ; 
 
int main(){
	
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	int t ; 
 
	cin >> t ; 
 
	while(t--){
 
		for(int i = 1 ; i <= 3 ; i++) cin >> p[i].x >> p[i].y ; 
 
		if((p[2]-p[1])%(p[3]-p[1]) > 0) cout << "LEFT\n" ; 
	    else if((p[2]-p[1])%(p[3]-p[1]) < 0) cout << "RIGHT\n" ;
	    else cout << "TOUCH\n" ;  
 
	}
 
}

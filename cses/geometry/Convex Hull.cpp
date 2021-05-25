#include<bits/stdc++.h>
 
#define ll long long 
#define sz size 
 
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
struct Point{
 
	ll x, y ; 
	Point(long long x = 0, long long y = 0) : x(x), y(y) {}
	ll operator %(Point a) { return (x*a.y) - (y*a.x) ; }
	ll operator *(Point a) { return (a.x*x) + (a.y*y) ; }
	Point operator -(Point a) { return Point(x-a.x, y-a.y) ; }
	bool operator <(Point a) { 
		if(x == a.x) return  y < a.y ; 
		return x < a.x ; 
	}
 
} ;
 
Point p[maxn] ;
int n ; 
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> p[i].x >> p[i].y ; 
 
	sort(p + 1, p + 1 + n) ; 
 
	vector<Point> lo, up ; 
 
	for(int i = 1 ; i <= n ; i++){
		while(up.size() > 1 && (up[up.sz()-1] - up[up.sz()-2])%(p[i] - up[up.size() - 2]) > 0) up.pop_back() ;
		up.push_back(p[i]) ;
	} 
 
	for(int i = 1 ; i <= n ; i++){
		while(lo.size() > 1 && (lo[lo.sz()-1] - lo[lo.sz()-2])%(p[i] - lo[lo.size() - 2]) < 0) lo.pop_back() ;
		lo.push_back(p[i]) ;
	}
 
	up.pop_back() ; // tira o ultimo -> ultimo do lo
 
	cout << up.size() + lo.size() - 1 << "\n" ; // ignora o 1o do low -> 1o do upper  
 
	for(auto a : up) cout << a.x << " " << a.y << "\n" ; 
	for(int i = 1 ; i < lo.size() ; i++) cout << lo[i].x << " " << lo[i].y << "\n" ; 
}

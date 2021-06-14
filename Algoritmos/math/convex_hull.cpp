#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m ; 

struct Point{

	long long x, y ; 

	Point operator - (Point a){ return Point{x - a.x, y - a.y} ; }
	Point operator + (Point a){ return Point{x + a.x, y + a.y} ; }
	
	ll operator * (Point a){ return {x*a.x + y*a.y} ; } // dot -> cos  
	ll operator % (Point a){ return {x*a.y - y*a.x} ; }
	ll dist(Point a){
		int dx = x - a.x ; 
		int dy = y - a.y ; 
		dx *= dx, dy *= dy ; 
		return dx + dy ; 
	}

	bool operator == (Point a){ return a.x == x && y == a.y ; }

} ; 

Point d[maxn] ; 

bool cmp(Point a, Point b){
	if(a.x != b.x) return a.x < b.x ; 
	return a.y < b.y ; 
}

int main(){
    
    bool ok = 1 ; 

    cin >> n ; 
    for(int i = 1 ; i <= n ; i++) cin >> d[i].x >> d[i].y ; 

    sort(d + 1, d + 1 + n, cmp) ; 
    vector<Point> upper, low ; 

    for(int i = 1 ; i <= n ; i++){
    	while(upper.size() > 1 && (upper[upper.size()-1] - upper[upper.size()-2])%(d[i] - upper[upper.size()-2]) > 0) upper.pop_back() ; 
    	upper.push_back(d[i]) ; 
    }

    for(int i = 1 ; i <= n ; i++){
    	while(low.size() > 1 && (low[low.size()-1] - low[low.size()-2])%(d[i] - low[low.size()-2]) < 0) low.pop_back() ; 
        low.push_back(d[i]) ; 
    }

    upper.pop_back() ; 

    cout << upper.size() + low.size() - 1 << "\n" ; 

    for(auto a : upper) cout << a.x << " " << a.y << "\n" ; 
    for(int i = 1 ; i < low.size() ; i++) cout << low[i].x << " " << low[i].y << "\n" ; 

}
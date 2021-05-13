#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
struct Point{
 
	long long x, y ; 
	
	Point(long long x = 0, long long y = 0) : x(x), y(y) {}
	
	long long operator % (Point a){
		return x*a.y - y*a.x ; 
	}
 
	long long operator * (Point a){ return x*a.x + y*a.y ; }
 
	bool operator < (Point a){ 
		if(x != a.x) return x < a.x ; 
		return y < a.y ; 
	}
 
	Point operator - (Point a) {return Point(x-a.x, y-a.y) ; }
 
} ; 
 
Point v[maxn] ;
int n ;  
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i].x >> v[i].y ; 
 
	vector <Point> ans ; 
 
    sort(v+1, v+n+1) ; 
 
    for(int i = 1 ; i <= n ; i++){
    	while(ans.size() > 1 && ((ans[ans.size() -1] - ans[ans.size() - 2])%(v[i]- ans[ans.size() - 2])) > 0) ans.pop_back() ; 
    	ans.push_back(v[i]) ; 
    }
 
    vector<Point> low ; 
 
    for(int i = 1 ; i <= n ; i++){
    	while(low.size() > 1 && ((low[low.size() - 1] - low[low.size() - 2])%(v[i] - low[low.size() - 2])) < 0) low.pop_back() ; 
    	low.push_back(v[i]) ; 
    }
    ans.pop_back() ; 
    cout << ans.size() + low.size() - 1<< "\n" ; 
    for(Point i : ans) cout << i.x << " " << i.y << "\n" ; 
    for(int i = 1 ; i < low.size() ; i++) cout <<  low[i].x << " " << low[i].y << "\n" ; 
 
}

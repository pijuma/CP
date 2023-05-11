// https://open.kattis.com/problems/saintjohn
#include<bits/stdc++.h>
#define int long long
using namespace std ; 

#define pii pair<int,int> 
#define x first 
#define y second 

int l, L ; 
vector<pii> pto, hull ; 

int cross(pii a, pii b){ return a.first*b.second - a.second*b.first ; }
pii sub(pii a, pii b){ return {a.first-b.first, a.second-b.second} ; }
int sig(int a){ 
	if(a > 0) return 1 ; 
	else if(a < 0) return -1 ; 
	return 0 ; 
}

void convex(){

	sort(pto.begin(), pto.end()) ; 

	// cout << "Pontos\n" ; 

	// for(auto a : pto) cout << a.first << " " << a.second << "\n" ; 
	vector<pii> low, up ; 

	for(int i = 0 ; i < pto.size() ; i++){
		while(up.size() > 1 && cross(sub(up[up.size()-1], up[up.size()-2]), sub(pto[i], up[up.size()-2])) > 0) up.pop_back() ; 
		up.push_back(pto[i]) ; 
	}

	for(int i = 0 ; i < pto.size() ; i++){
		while(low.size() > 1 && cross(sub(low[low.size()-1], low[low.size()-2]), sub(pto[i], low[low.size()-2])) < 0) low.pop_back() ; 
		low.push_back(pto[i]) ; 
	}

	for(auto a : up) hull.push_back(a) ; 
		reverse(low.begin(), low.end()) ; 
	for(int i = 1 ; i < low.size() - 1 ; i++) hull.push_back(low[i]) ; 

	// cout << "Hull\n" ; 

 //    for(auto a : hull) cout << a.first << " " << a.second << "\n" ; 

}

// faz bb p descobrir em q triangulo ele ta 
// e ve se ele ta dentro 

bool is_onseg(pii a, pii b, pii c){
	return (a.x >= min(b.x, c.x) && a.x <= max(b.x, c.x) && a.y >= min(b.y, c.y) && a.y <= max(b.y, c.y)) ; 
}

bool is_in(int x, int y){

	pii pt = {x, y} ; 

	int ini = 1, fim = hull.size() - 2, mid, best = -1 ; 

	while(ini <= fim){
		
		mid = (ini + fim)>>1 ;

		int p1 = sig(cross(sub(hull[mid], hull[0]), sub(pt, hull[0]))) ; 
		int p2 = sig(cross(sub(hull[mid+1], hull[0]), sub(pt, hull[0]))) ; 

		if(p1 == 0){
			if(is_onseg(pt, hull[mid], hull[0])) {
				//cout << pt.x << " " << pt.y << " " << hull[mid].x << " " << hull[mid].y << " " << hull[0].x << " " << hull[0].y << "\n" ; 
				return 1 ; 
			}
			return 0 ; 
		}

		if(p2 == 0){
			if(is_onseg(pt, hull[mid+1], hull[0])){
				//cout << hull[mid+1].x << " " <<  hull[mid+1].y << "\n" ; 
				return 1 ;
			} 
			return 0 ; 
		}

		if(p1 != p2){
			best = mid ; break ; 
		}

		if(p1 == 1) fim = mid - 1 ; 
		else ini = mid + 1 ; 

	}

	// cout << "fixo\n" ; 
	// cout << hull[0].first << " " << hull[0].second << "\n" ; 
	// cout << sig(cross(sub(hull[2], hull[0]), sub(pt, hull[0]))) << "\n" ; 

	if(best == -1) return 0 ; 
	//cout << hull[best].first << " " << hull[best].second <<" " << hull[best+1].first << " " << hull[best+1].second << "\n"; // o pto ta no triangulo de mid e mid+1


	mid = best ; 

	int area_t = abs(cross(sub(hull[mid], hull[0]), sub(hull[mid+1], hull[0]))) ; 

	// area 3 triangulos 

	int a1 = abs(cross(sub(hull[mid], hull[0]), sub(pt, hull[0]))) ; 
	int a2 = abs(cross(sub(hull[mid], pt), sub(hull[mid+1], pt))) ; 
	int a3 = abs(cross(sub(hull[0], pt), sub(hull[mid+1], pt))) ; 

	return (a1 + a2 + a3 == area_t) ; 

}

int32_t main(){

	cin >> L ; // grandes 

	for(int i = 1 ; i <= L ; i++){
		int x, y ; cin >> x >> y ; 
		pto.push_back({x, y}) ; 
	}

	convex() ; 

	cin >> l ; // pequenas ; 

	int ct = 0 ; 

	for(int i = 1 ; i <= l ; i++){
		int x, y ; cin >> x >> y ; 
		ct += is_in(x, y) ; 
	}

	cout << ct << "\n" ; 

}

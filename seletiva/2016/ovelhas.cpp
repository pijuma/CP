#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int,int> 
using namespace std ; 

const int inf = 1e9 + 10 ; 
const int maxn = 2e5 + 5 ; 

// faz o convex hull e p cada ponto vê se está 
// dentro ou fora do convex fznd bb em qual triang. ele está
// e checando se a area do triangulo ta ok 
// caso "extra": estar no limite do lado 

int n, q ; 
pii ptos[maxn], qr[maxn] ; 

pii sub(pii a, pii b){ return {a.x - b.x, a.y - b.y} ; }
int cross(pii a, pii b){ return a.x*b.y - a.y*b.x ; }

int reta(){

	int ans = 0 ; 

	int mx_x = -inf, mn_x = inf, mx_y = -inf, mn_y = inf ;

	for(int i = 1 ; i <= n ; i++){
		mx_y = max(mx_y, ptos[i].y), mn_y = min(mn_y, ptos[i].y) ; 
		mx_x = max(mx_x, ptos[i].x), mn_x = min(mn_x, ptos[i].x) ; 
	}

	for(int i = 1 ; i <= q ; i++){
		
		if(cross(sub(ptos[1], qr[i]), sub(ptos[2], qr[i])) == 0LL){ // colinear
			if(qr[i].x >= mn_x && qr[i].x <= mx_x && qr[i].y >= mn_y && qr[i].y <= mx_y){ // ta no intervalo ? 
				ans++ ; 
			}

		}

	}

	return ans ; 

}

vector<pii> convex(){

	vector<pii> up, low ; 

	sort(ptos + 1, ptos + 1 + n) ; 

	for(int i = 1 ; i <= n ; i++){
		while(up.size() > 1 && cross(sub(up.back(), up[up.size() - 2]), sub(ptos[i], up[up.size() - 2])) >= 0) up.pop_back() ;  
		up.push_back(ptos[i]) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		while(low.size() > 1 && cross(sub(low.back(), low[low.size() - 2]), sub(ptos[i], low[low.size() - 2])) <= 0) low.pop_back() ;  
		low.push_back(ptos[i]) ; 
	}

	vector<pii> hull ; 

	for(auto a : up) hull.push_back(a) ; 
	for(int i = low.size() - 2 ; i > 0 ; i--) hull.push_back(low[i]) ; 

	return hull ; 

}

bool onseg(pii a, pii b, pii c){ // a ta na reta bc 
	return min(b.x, c.x) <= a.x && a.x <= max(b.x, c.x) && a.y >= min(c.y, b.y) && a.y <= max(c.y, b.y) ; 
}

bool inv(int a, int b){ return a < 0 && b > 0 ; }

bool inside(pii a, pii b, pii c, pii p){

	int area = abs(cross(sub(b, a), sub(c, a))) ; 

	int a1 = cross(sub(a, p), sub(b, p)) ;
	int a2 = cross(sub(a, p), sub(c, p)) ;
	int a3 = cross(sub(b, p), sub(c, p)) ;

	return ((abs(a1) + abs(a2) + abs(a3)) == area) ; 

}

int sig(int a){return (a > 0 ? 1 : -1) ; }

int make(){

	vector<pii> hull = convex() ; 
	int ans = 0 ; 

	// cout << hull[0].x << " " << hull[0].y << "\n" ;
	// for(int i = 0 ; i < hull.size() ; i++) cout << hull[i].x << " " << hull[i].y << "\n" ; 
	// cout << "\n" ; 

	for(int i = 1 ; i <= q ; i++){

		int ini = 1, fim = hull.size() - 2, mid, best = -1 ;
		// procurar o triangulo q ele fica -> onde tem inversão 
		// se tiver colinear com o lado e nele conta mais 1 e n ve c ta dentro dps 
		// lado ptos[mid] com ptos[mid+1]

		while(ini <= fim){
			
			mid = (ini + fim)>>1 ; 

			if(cross(sub(hull[0], qr[i]), sub(hull[mid], qr[i])) == 0){ // testa se eh colinear com um dos lados 
				if(onseg(qr[i], hull[0], hull[mid])) ans++ ; 
				best = -1 ;
				break ;
			}

			if(cross(sub(hull[0], qr[i]), sub(hull[mid+1], qr[i])) == 0){ // testa se eh colinear com um dos lados 
				if(onseg(qr[i], hull[0], hull[mid+1])) ans++ ; 
				best = -1 ; 
				break ;
			}

			int p1 = sig(cross(sub(qr[i], hull[mid]), sub(hull[0], hull[mid]))) ; 
			int p2 = sig(cross(sub(qr[i], hull[mid+1]), sub(hull[0], hull[mid+1]))) ;

			if(p1 != p2){
				best = mid ; 
				break ;
			}

			if(p1 == -1) ini = mid + 1 ; 
			else fim = mid - 1 ; 

		}  

		if(best == -1) continue ; 
		if(inside(hull[0], hull[best], hull[best+1], qr[i])) ans++ ; // vê se ta dentro do triang.

	}

	return ans ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> ptos[i].x >> ptos[i].y ; 
	for(int i = 1 ; i <= q ; i++) cin >> qr[i].x >> qr[i].y ;

	// se tds pts forem colineares preciso checar qts estão na linha 

	bool col = 1 ; 
    for(int i = 3 ; i <= n ; i++){
    	if(cross(sub(ptos[1], ptos[i]), sub(ptos[2], ptos[i])) != 0) col = 0 ; 
    }

    if(col){ // n tem convex -> é uma reta p cada pto tem q ver se cruza só 
    	cout << reta() << "\n" ;
    }

    else cout << make() << "\n" ; 

}

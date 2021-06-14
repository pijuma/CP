#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxn = 1e4 ; 

int n, m ; 

struct Point{

	long long x, y ; 

	Point operator - (Point a) const { return Point{x - a.x, y - a.y} ; }
	Point operator + (Point a)const { return Point{x + a.x, y + a.y} ; }
	
	ll operator * (Point a)const{ return {x*a.x + y*a.y} ; } // dot -> cos  
	ll operator % (Point a)const{ return {x*a.y - y*a.x} ; }
	ll dist(Point a){
		int dx = x - a.x ; 
		int dy = y - a.y ; 
		dx *= dx, dy *= dy ; 
		return dx + dy ; 
	}

	bool operator == (Point a){ return a.x == x && y == a.y ; }

} ; 

Point d[10] ; 

int main(){
    
    cin >> n ; 
    for(int i = 1 ; i <= n ; i++) cin >> d[i].x >> d[i].y ; 

    bool ok = 1 ; 

    // checar se tá no 1o quad -> cos > 0 e sen > 0 -> angulo entre d2d1d3 é agudo 
    
    ok &= ((d[2] - d[1])%(d[3] - d[1]) > 0) ;
    ok &= ((d[2] - d[1])*(d[3] - d[1]) > 0) ;

    // mesmo comprimento 
    ok &= d[1].dist(d[2]) == d[1].dist(d[3]) ; 

    // colineares 2, 3, 4 e 5 -> cross 0  
    ok &= ((d[3] - d[2])%(d[4] - d[2]) == 0) ; 
    ok &= ((d[5] - d[2])%(d[4] - d[2]) == 0) ;
    
    // ponto médio = n precisa /2 pq ta comparando 
    ok &= ((d[2] + d[3]) == (d[4] + d[5])) ; 

    // p4p6 e p5p7 são perpendiculares a p2p3 -> cos = 0 
    ok &= ((d[6] - d[4])*(d[3] - d[4]) == 0) ;
    ok &= ((d[7] - d[5])*(d[2] - d[5]) == 0) ;  

    // segmento p1p6 intercepta p2p3 em um unico ponto faz fixando em 2 e ve se cruza dot de sinal oposto
    // nesse caso tem edge de colinear ou seja cross n pode ser 0 
    if(((d[2] - d[1])%(d[6] - d[1])) == 0 || ((d[6] - d[1])%(d[3] - d[1])) == 0) ok = false ; 
    if(((d[1] - d[2])%(d[3] - d[2])) == 0 || ((d[6] - d[2])%(d[3] - d[2])) == 0) ok = false ; 

    ok &= (((d[2] - d[1])%(d[6] - d[1]) > 0 ) != ((d[3] - d[1])%(d[6] - d[1]) > 0)) ;
    ok &= (((d[1] - d[3])%(d[2] - d[3]) > 0 ) != ((d[6] - d[3])%(d[2] - d[3]) > 0)) ;

}
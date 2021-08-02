#include<bits/stdc++.h>
using namespace std ; 

struct Point{

	long long x, y ; 

	Point(long long x = 0, long long y = 0) : x(x), y(y) {}

	Point operator - (Point a) const { return Point((x - a.x), (y - a.y)) ; } //jogar p origem

	long long operator * (Point a) const { //dot - escalar - cosseno x1x2 + y1y2
		return (x*a.x) + (y*a.y) ; 
	}

	long long operator % (Point a) const{ //cross - vetorial - seno 
		return (x*a.y) - (y*a.x) ;
	}

	bool operator == (Point a) const { return a.x == x && a.y == y ; }

	Point operator + (Point a) const {return Point ((x+a.x), (y+a.y)) ; } //ponto medio 

	long long dist (Point a){

		long long dx = (x-a.x) ;
		long long dy = (y-a.y) ;
		dx*=dx, dy*=dy ; 
		return dx + dy ; 

	}


} ;

Point b[8] ; 

int main(){

	for(int i = 1 ; i <= 7 ; i++) cin >> b[i].x >> b[i].y ; 

	//O ângulo P2P1P3 é agudo (vértice em P1); -> sen>0 & cos > 0 
	bool ok = 1 ;
    ok &= ((b[2]-b[1])%(b[3]-b[1]) > 0) ;
    ok &= ((b[2] - b[1])*(b[3]-b[1]) > 0) ;

    //Os segmentos P1P2 e P1P3 têm o mesmo comprimento; 

    ok &= (b[1].dist(b[2]) == b[1].dist(b[3])) ; 

    // Os pontos P2, P3, P4 e P5 são colineares; -> sen = 0 -> 180°/0° 

    ok &= ((b[3] - b[2])%(b[4] - b[2]) == 0) ; 
    ok &= ((b[5] - b[2])%(b[4] - b[2]) == 0) ; 

    //Os pontos médios dos segmentos P2P3 e P4P5 são coincidentes; 

    ok &= ((b[2] + b[3]) == (b[4] + b[5])) ;  

    //O segmento P2P3 tem comprimento maior que o segmento P4P5; 
    ok &= (b[2].dist(b[3]) > b[4].dist(b[5])) ;

    //Os segmentos P4P6 e P5P7 são perpendiculares ao segmento P2P3; -> cos = 0
    ok &= ((b[6]-b[4])*(b[3] - b[4]) == 0) ; 
    ok &= ((b[7] - b[5])*(b[3] - b[5]) == 0) ;

    //Os segmentos P4P6 e P5P7 têm o mesmo comprimento; 
    ok &= ((b[4].dist(b[6])) == (b[5].dist(b[7])));

    //Formalmente, o segmento P1P6 deve interceptar a reta que contém o segmento P2P3 em um único ponto. 
    // como é emú um nico ponto: temos que checar colinearidade 
    if((b[2]-b[1])%(b[6]-b[1]) == 0 || (b[3]-b[1])%(b[6]-b[1]) == 0) ok = false ; 
    if((b[1]-b[2])%(b[3]-b[2]) == 0 || (b[6]-b[2])%(b[3]-b[2]) == 0) ok = false ; 
    ok &= ((b[2]-b[1])%(b[6]-b[1]) > 0) != ((b[3]-b[1])%(b[6]-b[1]) > 0) ; // faz p2%p6 & p3%p6 -> p1
    ok &= ((b[1]-b[2])%(b[3]-b[2]) > 0) != ((b[6]-b[2])%(b[3]-b[2]) > 0) ; // fixa b2 e faz b1b3 e b3b6

    cout << (ok ? "S\n" : "N\n") ; 
}

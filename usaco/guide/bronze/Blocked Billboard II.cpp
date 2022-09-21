#include<bits/stdc++.h>
using namespace std ;

int x22, x12, x21, x11, y11, y21, y12, y22 ;

int inter(){

    int x = max(0, min(x22, x12)-max(x11, x21));
	int y = max(0, min(y12, y22)-max(y21, y11));

	return x * y;
}

int main(){

    ifstream cin("billboard.in");
    ofstream cout("billboard.out");

    cin >> x21 >> y21 >> x22 >> y22 ;
    cin >> x11 >> y11 >> x12 >> y12 ;

    int area = abs(y22-y21)*abs(x22-x21) ;

    bool ok = 0 ;

    if(x11 <= x21 && x22 <= x12 && ((y22>=y11 && y22 <= y12) || (y21 >= y11 && y21 <= y12))) ok = 1 ;
    else if(y21 >= y11 && y22 <= y12 &&((x22 >= x11 && x22 <= x12)||(x21>=x11 && x11<=x12))) ok = 1 ;

    cout << (ok ? area - inter() : area) << "\n" ;

}

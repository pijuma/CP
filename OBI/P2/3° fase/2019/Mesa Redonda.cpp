#include<bits/stdc++.h>
using namespace std ;

int a, b, la, lb, lc ;
int main(){

    cin >> a ;
    cin >> b ;
    la = a%3 ;
    lb = b%3 ;
    if(la == lb) lb = (b+1)%3 ;
    cout << 3 - la - lb ;
}

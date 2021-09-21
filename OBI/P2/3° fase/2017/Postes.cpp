// separados 2m
// h = 1m
// < 50cm subst
// < 85cm
// >85 normal
#include<bits/stdc++.h>
using namespace std ;

int n, r, s, a ;

int main(){

    cin >> n ;

    for(int i = 1 ; i <= n ; i++){
        cin >> a ;
        if(a < 50) s++ ;
        else if(a < 85) r++ ;
    }

    cout << s << " " << r ;
}

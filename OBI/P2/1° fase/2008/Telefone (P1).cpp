#include<bits/stdc++.h>
using namespace std ;

string n ;

int main(){

    cin >> n ;

    for(int i = 0 ; i < n.size() ; i++){

        char atu = n[i] ;

        if(atu == '1' || atu == '2' ||atu == '3' ||atu == '4' ||atu == '5' ||atu == '6' ||atu == '7' ||atu == '8' ||atu == '9' ||atu == '0' ) continue ;

        if(atu == 'A' || atu == 'B'|| atu == 'C') n[i] = '2' ;

        else if(atu == 'D' || atu == 'E'|| atu == 'F') n[i] = '3' ;

        else if(atu == 'G' || atu == 'H'|| atu == 'I') n[i] = '4' ;

        else if(atu == 'J' || atu == 'K'|| atu == 'L') n[i] = '5' ;

        else if(atu == 'M' || atu == 'N'|| atu == 'O') n[i] = '6' ;

        else if(atu == 'P' || atu == 'Q'|| atu == 'R' || atu == 'S') n[i] = '7' ;

        else if(atu == 'T' || atu == 'U'|| atu == 'V') n[i] = '8' ;

        else if(atu == 'W' || atu == 'X'|| atu == 'Y' || atu == 'Z') n[i] = '9' ;

        else if(atu == '*' || atu == '#' || atu == '-') continue ;
    }

    for(int i = 0 ; i < n.size() ; i++) cout << n[i] ;
}

#include<bits/stdc++.h>
using namespace std ;

int n ;
map<char, int> at, tot, at2 ;
string s, b, b2 ;

int main(){


	ifstream cin("blocks.in");
    ofstream cout("blocks.out");

    cin >> n ;

    for(int i = 1 ; i <= n ; i++){
        cin >> s ;
        at.clear(), at2.clear() ;
        for(auto a : s) at[a]++ ;
        cin >> s ;
        for(auto a : s) at2[a]++ ;
        for(char j = 'a' ; j <= 'z' ; j++) tot[j] += max(at[j], at2[j]) ;
    }


    for(char i = 'a' ; i <= 'z' ; i++) cout << tot[i] << "\n" ;


}

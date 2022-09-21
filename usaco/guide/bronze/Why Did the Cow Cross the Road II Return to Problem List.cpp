#include<bits/stdc++.h>
using namespace std ;

int in[60], x, out[60] ;
string s  ;

int main(){

    ifstream cin("circlecross.in");
    ofstream cout("circlecross.out");

    cin >> s ;

    for(char i = 'A' ; i <= 'Z' ; i++) in[i-'A'] = -1 ;

    for(int i = 0 ; i < s.size() ; i++){
        if((in[s[i]-'A'])==-1) in[s[i]-'A'] = i ;
        out[s[i]-'A'] = i ;
    }

    //for(char i = 'A' ; i <= 'Z' ; i++) cout << in[i-'A'] << " " << out[i-'A'] << "\n" ;

    for(char i = 'A' ; i <= 'Z' ; i++){
        for(char j = 'A' ; j <= 'Z' ; j++){
            if(in[i-'A'] < in[j-'A'] && in[j-'A'] < out[i-'A'] && out[j-'A'] > out[i-'A']) x++ ;
        }
    }

    cout << x << "\n" ;

}

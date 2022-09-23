#include<bits/stdc++.h>
using namespace std ;

int n ;
map<string, int> ctr ;
string s ;
// d 3
// abc d abc

bool check(int k){

    ctr.clear() ;

    for(int i = 0 ; i + k - 1 < s.size() ; i++){
        string att = "" ;
        for(int j = i ; j < i + k ; j++) att += s[j] ;
        //cout << att << "\n" ;
        if(ctr.find(att) != ctr.end()) return 0 ;
        ctr[att] = 1 ;
    }


    return 1 ;

}

int main(){

    ifstream cin("whereami.in");
    ofstream cout("whereami.out");

    cin >> n >> s ;

    int ini = 1, fim = s.size() + 1, mid, best = 0 ;

    //check(1) ;

    while(ini <= fim){
        mid = (ini + fim)>>1 ;
        if(check(mid)) best = mid, fim = mid - 1 ;
        else ini = mid + 1 ;
    }

    cout << best << "\n" ;

}

#include<bits/stdc++.h>
using namespace std ;
 
// se n * (n+1)/2 n for par ent�o n eh possivel
// se for cada set ter� soma n*(n+1)/4
// assim checamos se o ultimo valor eh divisivel pela soma
// se for adicionamos ele a um dos sets e pegamos junto o 1 e o anterior(1, n, n-1)
// se nn eh divisivel por n+1
// assim fazemos n, 1, 2, n-1
 
long long n, s, px, sum, sumax ;
 
int main(){
 
    cin >> n ;
 
    sumax = (n*(n+1))/2 ;
 
    if(sumax%2 != 0){
 
        cout << "NO\n" ;
        return 0 ;
 
    }
 
    sumax /= 2 ;
 
    set<int> ve ;
    set<int> vd ;
 
    if(n == 3){
 
        cout << "YES\n" ;
        cout << "2\n" << "1 2\n" << "1\n" << "3\n" ;
        return 0 ;
 
    }
    else if(sumax%n == 0){
 
        long long t = sumax/n ;
 
        for(int i = 1 ; i <= t ; i++) ve.insert(i), ve.insert(n - i) ;
 
    }
 
    else{
 
        long long t = sumax/(n + 1) ;
 
        for(int i = 1 ; i <= t ; i++) ve.insert(i), ve.insert(n - i + 1) ;
 
    }
 
    vector<int> v ;
    vector<int> e ;
 
    for(int i = 1 ; i <= n ; i++){
 
        if(ve.find(i) != ve.end()) v.push_back(i) ;
        else e.push_back(i) ;
 
    }
 
    cout << "YES\n" ;
    cout << v.size() << endl  ;
    for(int i = 0 ; i < (int) v.size() ; i++) cout << v[i] << " " ;
    cout << endl ;
 
    cout << e.size() << endl ;
    for(int i = 0 ; i < (int) e.size() ; i++) cout << e[i] << " " ;
    cout << endl ;
 
}

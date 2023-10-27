#include<bits/stdc++.h>
using namespace std ; 

set<int> in ; 

struct S{
    int i, tp, id ; 
} ;

bool cmp(S a, S b){
    if(a.i != b.i) return a.i < b.i ; 
    return a.tp < b.tp ; 
}

int main(){

    int n ; cin >> n ; 

    vector<S> vec ; 

    for(int i = 1 ; i <= n ; i++){
        int l, r ; cin >> l >> r ; 
        S a ; a.i = l, a.tp = 0, a.id = i ; 
        vec.push_back(a) ; 
        a.i = r, a.tp = 1, a.id = i ; 
        vec.push_back(a) ; 
    }

    sort(vec.begin(), vec.end(), cmp) ;

    vector<int> resp ; 

    for(auto a : vec){
        if(!a.tp) in.insert(a.id) ; 
        else{
            if(in.find(a.id) == in.end()) continue ; 
            else{
                resp.push_back(a.i) ;
                in.clear() ;
            }
        }
    }

    cout << resp.size() << "\n" ; 
    for(auto a : resp) cout << a << " " ;
    cout << "\n" ;

}

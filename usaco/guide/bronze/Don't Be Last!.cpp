#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e4 + 5 ;

struct V{
    string name ; int qtd ;
} ;

int n, ct ;
map<string, int> id ;
map<int,int> f ;
map<int, string> bk ;
V vaca[maxn] ;

bool cmp(V a, V b){ return a.qtd <= b.qtd ; }

int main(){

    ifstream cin("notlast.in");
    ofstream cout("notlast.out");

    cin >> n ;

    id["Bessie"] = 1 ; id["Elsie"] = 2 ;
    id["Daisy"] = 3 ; id["Henrietta"] = 4 ; id["Gertie"] = 5 ;
    id["Maggie"] = 6 ; id["Annabelle"] = 7 ;

    bk[1] = "Bessie" ; bk[2] = "Elsie" ;
    bk[3] = "Daisy" ; bk[4] = "Henrietta" ; bk[5] = "Gertie" ;
    bk[6] = "Maggie" ; bk[7] = "Annabelle" ;

    for(int i = 1 ; i <= 7 ; i++) vaca[i].qtd = 0, vaca[i].name = bk[i] ;

    for(int i = 1 ; i <= n ; i++){
        string s ; int vv ;
        cin >> s >> vv ;
       vaca[id[s]].qtd += vv ;
    }

    sort(vaca + 1, vaca + 8, cmp) ;

    int mn = vaca[1].qtd ;

    for(int i = 1 ; i <= 7 ; i++) f[vaca[i].qtd]++ ;
    string ans = "Tie" ;

    for(int i = 1 ; i <= 7 ; i++){
        if(vaca[i].qtd == mn) continue ;
        else if(f[vaca[i].qtd] == 1){
            ans = vaca[i].name ; break ;
        }
    }

    cout << ans << "\n" ;

}

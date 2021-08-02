#include<bits/stdc++.h>
using namespace std ;

vector<int> jogo[5] ;

int d, x, qd, qx, n ;
bool da, xe ;

int main(){

    // jogo[i] = j  ent i ganha de j

    cin >> n ;

    jogo[0].push_back(1), jogo[0].push_back(2) ;
    jogo[1].push_back(2), jogo[1].push_back(3) ;
    jogo[2].push_back(3), jogo[2].push_back(4) ;
    jogo[3].push_back(4), jogo[3].push_back(0) ;
    jogo[4].push_back(1), jogo[4].push_back(0) ;

    while(n--){

        cin >> d >> x ;

        for(int i = 0 ; i < jogo[d].size() ; i++){

            if(jogo[d][i] == x){

                qd++ ;
                break ;

            }

        }

        for(int i = 0 ; i < jogo[x].size() ; i++){

            if(jogo[x][i] == d){

                qx++ ;
                break ;

            }

        }

    }

    cout << (qd > qx ? "dario" : "xerxes") ;

}

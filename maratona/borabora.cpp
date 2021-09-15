#include <bits/stdc++.h>
using namespace std ;

int get(char c) {
    if (c == 'C') return 0 ;
    if (c == 'D') return 1 ;
    if (c == 'H') return 2 ; 
    return 3 ;
}

int N, P, M ;
vector<pair<int,int>> p[19] ;
queue<pair<int,int>> stock ;
pair<int,int> descarte ;

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    int g, l ;
    char opa ;
    while (cin >> P >> M >> N, P){

        while (!stock.empty()) stock.pop() ;

        for (int i = 0; i < P; i++) {
            p[i].clear() ;
            for (int j = 0; j < M; j++) {
                cin >> g >> opa ;
                p[i].push_back(pair<int,int>(g, get(opa))) ;
            }
        }

        cin >> g >> opa ;

        descarte = pair<int,int>(g, get(opa)) ;

        for (int i = P*M + 1; i < N; i++){
            cin >> g >> opa ;
            stock.push(pair<int,int>(g, get(opa))) ;
        }

        int jog = 0, dir = 1 ;
        bool apply = true ;

        if (descarte.first == 12)dir = -1 ;

        while (true){

            if (apply && descarte.first == 7){
                p[jog].push_back(stock.front()) ;
                stock.pop() ;
                p[jog].push_back(stock.front()) ;
                stock.pop() ;
                apply = false ;
            }
            else if (apply && descarte.first == 1){
                p[jog].push_back(stock.front()) ;
                stock.pop() ;
                apply = false ;
            }
            else if (apply && descarte.first == 11) apply = false ;
            else{
                pair<int,int> val = pair<int,int>(0, 0) ;
                bool found = false ;
                apply = false ;
                for (int i = 0; i < p[jog].size(); i++){
                    g = p[jog][i].first ;
                    l = p[jog][i].second ;

                    if (g == descarte.first || l == descarte.second){
                        found = true ; break ;
                    }
                }
                if (!found){p[jog].push_back(stock.front());stock.pop() ; }
                
                found = false ;
                int idx = 0 ;

                for (int i = 0; i < p[jog].size(); i++){
                    g = p[jog][i].first ;
                    l = p[jog][i].second ;

                    if (g == descarte.first || l == descarte.second){
                        found = true ;
                        if (val < pair<int,int>(g, l)){idx = i, val = pair<int,int>(g, l) ; }
                    }

                }

                if (found){
                    apply = true ;
                    descarte = p[jog][idx] ;
                    for (int i = idx; i < p[jog].size() - 1 ; i++) p[jog][i] = p[jog][i+1] ;
                    p[jog].pop_back() ;
                }

            }

            if (p[jog].empty()) break ;

            if (apply && descarte.first == 12) dir = -dir ;
            jog = (jog + dir + P) % P ;
        }

        cout << jog + 1 << "\n";

    }

}

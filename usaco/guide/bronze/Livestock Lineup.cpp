#include<bits/stdc++.h>
using namespace std ;

const int maxn = 22 ;

int n, ct, grau[maxn], dist[maxn][maxn] ;
vector<int> grafo[maxn], ord ;
vector<vector<string>> resp ;
map<string, int> id ;
map<int,string> bk ;

vector<string> get_ans(vector<int> mask){

    vector<string> ans ;

    for(int i = 0 ; i < ct ; i++){
        string kra = bk[mask[i]] ;
        ans.push_back(kra) ;
    }

    return ans ;

}

bool cmp(vector<string> a, vector<string> b){

    for(int i = 0 ; i < a.size() ; i++){
        if(a[i][0] != b[i][0]){
            return a[i][0] < b[i][0] ;
        }
    }

    return 1 ;

}

int main(){


    ifstream cin("lineup.in");
    ofstream cout("lineup.out");

    cin >> n ;

    bk[0] = "Bessie" ; bk[1] = "Buttercup" ;
    bk[2] = "Belinda" ; bk[3] = "Beatrice" ;
    bk[4] = "Bella" ; bk[5] = "Blue" ;
    bk[6] = "Betsy" ; bk[7] = "Sue" ;

    id["Bessie"] = 0 ; id["Buttercup"] = 1 ;
    id["Belinda"] = 2 ; id["Beatrice"] = 3 ;
    id["Bella"] = 4 ; id["Blue"] = 5 ;
    id["Betsy"] = 6 ; id["Sue"] = 7 ;

    ct = 8 ;

    for(int i = 1 ; i <= n ; i++){
        string s, nm1, nm2 ;
        cin >> nm1 ;
        cin >> s ; cin >> s ; cin >> s ; cin >> s ;
        cin >> nm2 ;
        dist[id[nm1]][id[nm2]] = 1 ;
        dist[id[nm2]][id[nm1]] = 1 ;
    }


    vector<int> tryy ;

    for(int i = 0 ; i < ct ; i++) tryy.push_back(i) ;

    do{

        bool ok = 1 ;

        for(int i = 0 ; i < ct ; i++){
            int kra = tryy[i] ;
            for(int j = 0 ; j < ct ; j++){
                int kra2 = tryy[j] ;
                if(dist[kra][kra2]){
                    if(abs(j-i) != 1) ok = 0 ;
                }
            }
        }
        if(ok){
            resp.push_back(get_ans(tryy)) ;
        }


    }while(next_permutation(tryy.begin(), tryy.end())) ;

    sort(resp.begin(), resp.end()) ;

    for(int i = 0 ; i < resp[0].size() ; i++){
            cout << resp[0][i] ;
            if(i != resp[0].size() - 1) cout << "\n" ;
    }

    cout << "\n" ;

}

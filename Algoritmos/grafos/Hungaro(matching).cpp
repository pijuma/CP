#include<bits/stdc++.h>
#define ld long double // precisa 
using namespace std ; 

const int maxn = 110 ; 

ld a[maxn][maxn] ;
int ans[maxn] ; 

// Hungaro
// Resolve o problema de assignment (matriz n x m) -> liga os caras
// de n com os caras de m 
// Colocar os valores da matriz em 'a' (pode < 0)
// 0 indexado 
// resolve problema de matching -> calcula a soma minima
// pareando os kras de forma perfeita
// ligação entre o cara i e j tem um custo 
// tem que depender só de i e j - n pode depender de outras lig
// O(n^3)

template<typename T> struct hungarian {
    int n, m;
    vector<vector<T>> a;
    vector<T> u, v;
    vector<int> p, way;
    T inf;
 
    hungarian(int n_, int m_) : n(n_), m(m_), u(m+1), v(m+1), p(m+1), way(m+1) {
        a = vector<vector<T>>(n, vector<T>(m));
        inf = numeric_limits<T>::max();
    }
    pair<T, vector<int>> assignment() { // retorna o custo (.first) e um vetor com os pareamentos
        //v[i] vai guardar o cara que ta ligando com o i 
        for (int i = 1; i <= n; i++) {
            p[0] = i;
            int j0 = 0;
            vector<T> minv(m+1, inf);
            vector<int> used(m+1, 0);
            do {
                used[j0] = true;
                int i0 = p[j0], j1 = -1;
                T delta = inf;
                for (int j = 1; j <= m; j++) if (!used[j]) {
                    T cur = a[i0-1][j-1] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
                for (int j = 0; j <= m; j++)
                    if (used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }
        vector<int> ans(m);
        for (int j = 1; j <= n; j++) ans[p[j]-1] = j-1;
        return make_pair(-v[0], ans);
    }
};

int main(){

    int n ; cin >> n ; 

    hungarian<ld> hungaro(n, n); 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ld b ; cin >> b ; 
            hungaro.a[i][j] = -log(b) ; 
        }
    }

    auto resp = hungaro.assignment() ; 

    for(int i = 0 ; i < n ; i++){
        ans[resp.second[i]] = i ; 
    }

    for(int i = 0 ; i < n ; i++) cout << ans[i] + 1 << " " ; 
    cout << "\n" ; 

}

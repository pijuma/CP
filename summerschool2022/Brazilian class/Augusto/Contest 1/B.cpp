#include<bits/stdc++.h>
using namespace std ; 

// liga um vertice 0 (fonte) aos problemas com cada aresta capacidade 1 
// liga cada problema a seus possiveis nomes e os pessiveis nomes a letra que começa 
// TODAS as arestas vão ter fluxo 1 ou 0 - queremos o fluxo maximo 
// inicia o fluxo em todas as arestas como 0 e cria um grafo auxiliar em que 
// as arestas na ordem direta representam o qto da capacidade ainda pode usar e na ordem 
// inversa o qto ja usou - servem p realocar o fluxo 
// indo da fonte ate o dreno pegamos a aresta de menor capacidade restante 
// e subtraimos esse valor de todas no caminho dela (na ordem normal), somamos nas ao contrario 
// e no grafo final alteramos o valor da aresta p capacidade total - restante 
// usa bfs/dfs 

#define toupper(x) (x >= 'a' ? x-'a'+'A' : x)
#define tolower(x) (x >= 'a' ? x : x-'A'+'a')

const int maxn = 110 ; 
const int MAX = 35 ; 

int t, n, ct ; 
int g[maxn][maxn], gg[maxn];
int mx[maxn], my[maxn], ud[maxn], v[MAX] ;
char w[MAX][MAX][maxn];
string s[maxn][maxn] ; 

int dfs(int x) {
    
    for(int i = 0; i < gg[x]; i++) {
        
        int y = g[x][i] ;

        if(!ud[y]){
            
            ud[y] = 1 ;

            if(my[y] == 0 || dfs(my[y])) {
                
                mx[x] = y, my[y] = x ;

                return 1 ;
            }

        }

    }

    return 0 ;

}

int main(){

	cin >> t ; 

	while(t--){

		cin >> n ; 

		memset(gg, 0, sizeof gg) ; memset(mx, 0, sizeof mx) ; memset(my, 0, sizeof my) ;

		for(int i = 1 ; i <= n ; i++){
			
			cin >> v[i] ; 
			
			for(int j = 0 ; j < v[i] ; j++){

				cin >> w[i][j] ; 
				s[i][j] = w[i][j] ; 

				int a = 30 + (w[i][j][0] >= 'a' ? w[i][j][0]-'a' : w[i][j][0]-'A') ; 

				g[a][gg[a]++] = i ; 

			}

		}

		int ans = 0 ; 


		for(int i = 30 ; i < n + 30 ; i++){
			if(!mx[i]){
				memset(ud, 0, sizeof ud) ; 
				if(dfs(i)) ans++ ; 
			}
		}

		cout << "Case #" << ++ct << ":\n" ; 

		for(int i = 30 ; i < n + 30 ; i++){
			
			for(int j = 0 ; j < v[mx[i]] ; j++){
				
				if(tolower(w[mx[i]][j][0]) == i - 30 + 'a') {
                    
                    printf("%c", toupper(w[mx[i]][j][0])) ;
                    
                    for(int k = 1; w[mx[i]][j][k]; k++) printf("%c", tolower(w[mx[i]][j][k])) ;
                    
                    cout << "\n" ; 
                    
                    break ;

                }

			}

		}

	}

}

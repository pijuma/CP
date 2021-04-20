#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define ff first
#define ss second 
#define _ ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
using namespace std ; 

// um ciclo completo é g[i] + r[i](ciclo)
// time = tempo[pai] + d[pai][filho] 
// se tempo%ciclo >= g[filho] -> soma ciclo - tempo%ciclo 
// checa smp se vale a pena att o novo valor 
// se tempo%ciclo < g[filho] -> att normal  

const int inf = 1e9 ; 
const int maxn = 5e4 + 5 ; 

struct aresta{
	int v, d, r, g ; 

	aresta(int b, int c, int di, int e){
	      v = b, d = c, r = e, g = di ; 
	}

} ; 

int n, m, ciclo, timer ; 
int tempo[maxn] ; 
vector<aresta> grafo[maxn] ; 

bool check(int t, int tot, int ind, int ab){

	if(t%tot >= ab) return 1 ; 
	return 0 ; 

}

int extratime(int t, int tot) {return (tot) - (t%tot) ; } 

int main(){
_
	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c, d, e ; 
		cin >> a >> b >> c >> d >> e ;
		grafo[a].push_back(aresta(b,c,d,e)) ;  
	}

	for(int i = 1 ; i <= n ; i++) tempo[i] = inf ; 
	tempo[1] = 0 ; 
    priority_queue < pii, vector < pii >, greater < pii > > fila ; 
    fila.push({0, 1}) ; 

    while(!fila.empty()){
    	
    	int pai = fila.top().ss ;
    	fila.pop() ; 

    	for(int i = 0 ; i < grafo[pai].size() ; i++){

    		int ab = grafo[pai][i].g, fe = grafo[pai][i].r, filho = grafo[pai][i].v, pes = grafo[pai][i].d ;
    		ciclo = ab + fe ;
    		timer = tempo[pai] + pes ; 

    		if(check(timer, ciclo, filho, ab)){

    			if(tempo[filho] > timer + extratime(timer, ciclo)){
    				tempo[filho] = timer + extratime(timer, ciclo) ; 
    				fila.push({tempo[filho], filho}) ; 
    			}

    		}

    		else{

    			if(tempo[filho] > timer){
    				tempo[filho] = timer ; 
    				fila.push({timer, filho}) ; 
    			}

    		}

    	}

    }

    if(tempo[n] == inf) cout << "-1\n" ; 
    else cout << tempo[n] << "\n" ; 

} 

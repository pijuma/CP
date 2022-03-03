// tem uma arvore 
// cada companhia produz uma materia smp dif - cada uma tem no minimo
// uma industria, essa ficam nos vertices 
// pode ter mais de uma industria numa msm cidade 
// as vzs uma precisa de material da outra
// queremos minimizar a dist a ser percorrida ao precisar de uma materia da ind G
// query: a companhia u (com empresas em x1, x2,...) precisa
// de material da companhia v (com empresas em y1, y2, ...)
// qual a menor dist?
// lca + centroid 
// pega de um centroid p outro
// guarda o mais prox e p subir do vertice p centroide e de um p outro
// usa o lca pra pegar a dist 
// atualiza o centroid p cada empresa q lê
// vendo se ela cria um novo caminho minimo 
// pega o min entre oq ja ta e o min entre o vertice ate o cara k (centroid)
// na query queremos o minimo de ir ate o centroid atual e a menor 
// dist q ele tem pra algm empresa A 
// lca em o(1) -> lca entre a e b é o cara na euler entre eles com menor nivel 

// #include "factories.h"
#include<bits/stdc++.h> 
using namespace std;

const int maxn = 1e6 + 5 ; 
const long long inf = 1e18 ; 
const int maxl = 21 ; 

int n, tab[maxl][maxn], log_[maxn], kra[maxn], dp[maxl][maxn], nivel[maxn], cent[maxn] ; 
long long dist[maxn], resp[maxn], pos[maxn] ; 
int sz[maxn], pai[maxn], timer ;
bool vis[maxn], mark[3*maxn] ; 
int tin[maxn], tout[maxn] ;  
vector<pair<int,int>> grafo[maxn] ; 
vector<int> euler ; 

int minn(int a, int b){return (nivel[a] < nivel[b] ? a : b) ; }

int lca(int u, int v){ 

	int r = max(pos[v], pos[u]), l = min(pos[v], pos[u]) ; 
	int d = log2(r-l+1) ; 

	return minn(dp[d][l], dp[d][r+1-(1<<d)]) ; 

}

long long find_dist(int a, int b){ return dist[a] + dist[b] - ((dist[lca(a, b)])<<1) ; }

void update_cent(int u){

	int k = u ; 

	while(k){
		resp[k] = min(resp[k], find_dist(u, k)) ; 
		k = pai[k] ; 
 	}

}

void ini(int u){

	int k = u ; 

	while(k){ resp[k] = inf ; k = pai[k] ; }

}

long long query(int x){

	int k = x ; long long ans = inf ; 

	while(k){
		if(resp[k] < ans) ans = min(ans, find_dist(x, k) + resp[k]) ; 
		k = pai[k] ; 
	}

	return ans ; 

}

long long Query(int S, int X[], int T, int Y[]) {

	long long ans = inf ; 

	for(int i = 0 ; i < S ; i++) update_cent(X[i]+1) ; 

	for(int i = 0 ; i < T ; i++) ans = min(ans, query(Y[i]+1)) ; 

	for(int i = 0 ; i < S ; i++) ini(X[i]+1) ; 

	return ans ; 

}

void dfs_cent(int v, int p){

	sz[v] = 1 ; 

	for(auto a : grafo[v]){
		if(cent[a.first] || a.first == p) continue ; 
		dfs_cent(a.first, v) ; 
		sz[v] += sz[a.first] ; 
	}

}

int find_cent(int v, int p, int szz){

	for(auto a : grafo[v]){
		if(a.first == p || cent[a.first] || (sz[a.first]<<1) <= szz) continue ;
		return find_cent(a.first, v, szz) ;  
	}

	return v ; 

}

void make_cent(int v, int p){

	dfs_cent(v, p) ; 

	int c = find_cent(v, p, sz[v]) ; 
	cent[c] = 1, pai[c] = p ; 

	for(auto a : grafo[c]){
		if(cent[a.first]) continue ; 
		make_cent(a.first, c) ; 
	}

}

void dfs(int v, int p){

	tin[v] = ++timer ;

	pos[v] = euler.size() ; 
	euler.push_back(v) ;

	for(auto a : grafo[v]){
		if(a.first == p) continue ; 
		nivel[a.first] = nivel[v] + 1 ; dist[a.first] = dist[v] + a.second ; 
		dfs(a.first, v) ; euler.push_back(v) ; 
	}

}

void build(){

	int qtd = euler.size() ; 

	for(int i = 0 ; (1<<i) <= qtd ; i++){
		for(int j = 1 ; j + (1<<i) <= qtd ; j++){
			if(!i) dp[i][j] = euler[j] ;
			else dp[i][j] = minn(dp[i-1][j], dp[i-1][j+(1<<(i-1))]) ;
		}
	}

}

void Init(int N, int A[], int B[], int D[]) {
    
    n = N ; 

    for(int i = 0 ; i < N - 1 ; i++){
    	grafo[A[i]+1].push_back({B[i]+1, D[i]}) ; 
    	grafo[B[i]+1].push_back({A[i]+1, D[i]}) ; 
    }

    euler.push_back(0) ; 
    dfs(1, 0) ; 
    make_cent(1, 0) ; 
    build() ; 

    for(int i = 0 ; i < N + 1 ; i++) resp[i] = inf ; 

}
 
// int main() {

//     // ios::sync_with_stdio(false); cin.tie(0);
 
//     int32_t N, Q; cin >> N >> Q;
//     int32_t A[N], B[N], D[N];
//     for(int i = 0; i < N-1; i++) {
//         cin >> A[i] >> B[i] >> D[i];
//     }
 
//     Init(N,A,B,D);

//     // cout << lca(0, 7) << " " << lca(3, 5) << "\n" ; 

//     while(Q--) {
//         int32_t S, T; cin >> S >> T;
//         int32_t X[S+1], Y[T+1];
//         for(int i = 0; i < S; i++) cin >> X[i];
//         for(int i = 0; i < T; i++) cin >> Y[i];
 
//         cout << Query(S,X,T,Y) << endl;
//     }
 
// }

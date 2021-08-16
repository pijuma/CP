#include<bits/stdc++.h>
#define pii pair<int,int> 

using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m, a, b, in[maxn], out[maxn], vis[maxn] ; 
vector<pii> grafo[maxn] ;
vector<int> odd ;  
stack<int> fila ; 

void no_ans(){
	cout << "IMPOSSIBLE\n" ; 
	exit(0) ; 
}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[a].push_back({b, i}) ; 
		in[b]++, out[a]++ ;  
	}

	for(int i = 1 ; i <= n ; i++){

		if(abs(in[i] - out[i]) > 1) no_ans() ; // ng pode ter dif maior q 1 

		if(abs(in[i] - out[i]) == 1) odd.push_back(i) ; // se tiver um são os impares 

	}

	if(odd.size() > 2) no_ans() ; // mais de 2 impares n tem resp 

	if(odd.size() == 2){ // dois impares -> devemos começar por um deles -> nesse caso queremos ir de 1 a n 
	    // ent o 1 deve ser impar
		if(odd[0] == 1) fila.push(1) ; 
		else if(odd[1] == 1) fila.push(1) ; 
		else no_ans() ; 

	}

	else fila.push(1) ; 

	vector<int> resp ; 

	while(!fila.empty()){

		int v = fila.top() ; 
		bool f = 0 ; 

		while(!grafo[v].empty()){

			int u = grafo[v].back().first, id = grafo[v].back().second ;
			grafo[v].pop_back() ; 

			if(!vis[id]){
				f = 1 ; 
				fila.push(u) ; 
				break ; 
			}

		}

		if(!f){
			fila.pop() ; resp.push_back(v) ; 
		}

	}

	reverse(resp.begin(), resp.end()) ; // fica ao contrario 
	// mas no bidirecionado n faz diferença 
	
	if(resp.size() != m + 1 || resp[0] != 1 || resp[resp.size() - 1] != n) no_ans() ; // checa se o ultimo eh n e o tamanho 
	else{
		for(int i = 0 ; i < resp.size() ; i++) cout << resp[i] << " " ; 
		cout << "\n" ; 
	} 

}

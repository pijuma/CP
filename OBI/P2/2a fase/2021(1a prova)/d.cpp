#include<bits/stdc++.h>
#define ll long long 
using namespace std ; 

const int maxn = 110 ; 

// começa cm a matriz de string 
// cada string vai ter um valor 
// temos q olhar p cada linha e cada coluna
// e ver a que tem apenas uma string sem valor ainda 
// pegamos essa subtraimos tds os valores ja achados na linha/coluna 
// e dividimos pela qtd da ocorrencia 
// e guardamos o valor achado 
// fazemos isso até ter algum valor n achado 
// depois sortamos as strings existentes e imprimimos o valor de cada uma 

ll n, m, v ; 
ll valor_linha[maxn], valor_coluna[maxn] ;
string matriz[maxn][maxn] ; 
vector<string> lista ; 
map<string, ll> valor ; 

int tem_linha(){
	
	for(int i = 1 ; i <= n ; i++){ // olhando cada linha
			vector<string> faltam ; 
			for(int j = 1 ; j <= m ; j++){
				if(valor.find(matriz[i][j]) == valor.end()){
					faltam.push_back(matriz[i][j]) ;
				} 
			}
			sort(faltam.begin(), faltam.end()) ; 
			faltam.erase(unique(faltam.begin(), faltam.end()), faltam.end()) ; 
			int qtd = 0 ; 
			for(int j = 0 ; j < faltam.size() ; j++) qtd++ ; 
			if(qtd == 1) return i ;  
	}

	return -1 ; 
}

int tem_col(){

	for(int j = 1 ; j <= m ; j++){
		vector<string> faltam ; 
		for(int i = 1 ; i <= n ; i++){
			if(valor.find(matriz[i][j]) == valor.end()) faltam.push_back(matriz[i][j]) ;
		}
		sort(faltam.begin(), faltam.end()) ; 
		faltam.erase(unique(faltam.begin(), faltam.end()), faltam.end()) ;
		int qtd = 0 ; 
		for(int i = 0 ; i < faltam.size() ; i++) qtd++ ; 
		if(qtd == 1) return j ; 
	}

	return -1 ; 
}

void read(){

	for(int i = 1 ; i <= n + 1 ; i++){
		
		for(int j = 1 ; j <= m + 1 ; j++){

			if(i == n + 1 && j == m + 1) return ; 
			if(i == n + 1){
				cin >> v ; 
				valor_coluna[j] = v ; 
			}

			else if(j == m + 1){
				cin >> v ; 
				valor_linha[i] = v ; 
			}

			else{
				cin >> matriz[i][j] ;
				lista.push_back(matriz[i][j]) ; 
			}

		}

	}

}

int main(){

	cin >> n >> m ; 

	read() ;  

	sort(lista.begin(), lista.end()) ; 
	lista.erase(unique(lista.begin(), lista.end()), lista.end()) ; 

	while(true){

		int pi, pj ; 

		pi = tem_linha() ;  

		// cout << pi << " " << pj << "\n" ; 

 		if(pi != -1){ // consigo descobrir da linha pi
		    ll sum = valor_linha[pi], freq = 0 ;  
		    string nope ; 
			for(int j = 1 ; j <= m ; j++){
				if(valor.find(matriz[pi][j]) != valor.end()) sum -= valor[matriz[pi][j]] ; 
				else{
					freq++ ; 
					nope = matriz[pi][j] ; 
				}  
			}
			valor[nope] = (sum/freq) ; 
		}

		pj = tem_col() ; 
		
		if(pi == -1 && pj == -1) break ; 

		if(pj != -1){
			ll sum = valor_coluna[pj], freq = 0 ; 
			string nope ; 
			for(int i = 1 ; i <= n ; i++){ 
				if(valor.find(matriz[i][pj]) != valor.end()) sum -= valor[matriz[i][pj]] ; 
				else{
					freq++ ; 
					nope = matriz[i][pj] ; 
				}
			}
			valor[nope] = (sum/freq) ; 
		}

	}

	for(int i = 0 ; i < lista.size() ; i++){
		cout << lista[i] << " " << valor[lista[i]] << "\n" ; 
	}

}

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2005 ; 

int n, x, y ; 
int d[maxn], doces[maxn], best[maxn] ; 
vector<pair<int,int>> tendas ; 
vector<pair<int,pair<int,int>>> pontos ; 

int main(){

  cin >> n ; 

  tendas.push_back({0, 0}) ; //começo  

  for(int i = 1 ; i <= n ; i++){
    cin >> x >> y ; 
    tendas.push_back({x, y}) ; 
  }

  for(int i = 0 ; i < n + 1 ; i++){
    
    for(int j = i + 1 ; j < n + 1 ; j++){
      
      int dx = tendas[i].first - tendas[j].first ; 
      int dy = tendas[i].second - tendas[j].second ; 

      pontos.push_back({dx*dx + dy*dy, {i, j}});

    }
  
  }

  sort(pontos.begin(), pontos.end()) ; 

  for(auto atual : pontos){
    
    int dist = atual.first ; 
    int a = atual.second.first, b = atual.second.second ;

    //já estamos pegando da menor p maior, porém n podemos pegar iguas tb 

    if(d[a] != dist){ //pega smp a qtd de doces da anterior c dist dif 
      d[a] = dist ; 
      doces[a] = best[a] ; 
    }

    if(d[b] != dist){
      d[b] = dist ; 
      doces[b] = best[b] ; 
    }

    if(a == 0) best[a] = max(best[a], doces[b] + 1) ; //b smp é >= a (nesse caso*(0,0))  

    else best[a] = max(best[a], doces[b]+1), best[b] = max(best[b], doces[a] + 1); // 2as direções

  }

  cout << best[0] << "\n" ; 

}

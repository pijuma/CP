#include<bits/stdc++.h>
using namespace std ; 

int n, ha ; 

vector<int> h ; 
vector<pair<int,int>> pv ; 

int main(){

	cin >> n ; 

	h.push_back(0) ; 

	for(int i = 1 ; i <= n ; i++){
		
		cin >> ha ; 

		if(ha != h.back()) h.push_back(ha) ; //é pico ou vale

	}

	h.push_back(0) ; 

	//num vale smp aumenta o n° num pico reduz -> vale separa 2 partes 
	// locais sem ser vale e pico n alteram 
	for(int i = 1 ; i < h.size() - 1 ; i++){

		if(h[i] > h[i-1] && h[i] > h[i+1]) pv.push_back({h[i], -1}) ; // pico
		if(h[i] < h[i-1] && h[i] < h[i+1]) pv.push_back({h[i], 1}) ; // vale 

	}

    sort(pv.begin(), pv.end()) ; 

    int maior = 2, resp = 2 ; 

    for(int i = 0 ; i < pv.size() ; i++){
    	resp += pv[i].second ; 
    	maior = max(maior, resp) ; 
    }

    cout << maior << "\n" ; 

}

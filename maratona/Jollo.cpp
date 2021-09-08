#include<bits/stdc++.h>
using namespace std ; 

int pa[5], po[5], v[55] ; 

int main(){

	while(true){
		cin >> pa[1] >> pa[2] >> pa[3] >> po[1] >> po[2] ; 
	    if(pa[1] == pa[2] && pa[3] == po[1] && po[1] == po[2] && po[2] == 0) return 0 ; 
	    vector<int> princesa ; 
	    princesa.push_back(pa[1]), princesa.push_back(pa[2]), princesa.push_back(pa[3]) ;
	    sort(princesa.begin(), princesa.end()) ;
	    v[pa[1]] = v[pa[2]] = v[pa[3]] = v[po[1]] = v[po[2]] = 1 ; 
	    int carta = -1 ; 
	    for(int i = 1 ; i <= 52 ; i++){
	    	if(v[i] == 0){
	    		vector<int> principe ;
	    		principe.push_back(i), principe.push_back(po[1]), principe.push_back(po[2]) ; 
	    		sort(principe.begin(), principe.end()) ; 
	    		int ra = 0, re = 0 ; 
	    		if(principe[2] < princesa[0]) ra++ ; 
	    		else re++ ; 
	    		if(principe[1] < princesa[2]) ra++ ; 
	    		else re++ ; 
	    		if(princesa[1] > principe[0]) ra++ ; 
	    		else re++ ; 
	    		if(re >= 2){
	    			carta = i ; 
	    			break ; 
	    		} 
	    	}
	    }
	    v[pa[1]] = v[pa[2]] = v[pa[3]] = v[po[1]] = v[po[2]] = 0 ;
	    cout << carta << "\n" ; 
	}

}

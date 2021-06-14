#include<bits/stdc++.h>
using namespace std ; 

int inv ; 

void merge(vector<int>&v){
	if(v.size() == 1) return ; 
	vector<int> ve, vd ; 
	int tam = v.size(), mid = tam/2 ; 
	for(int i = 0 ; i < mid ; i++) ve.push_back(v[i]) ; 
	for(int i = mid ; i < tam ; i++) vd.push_back(v[i]) ; 
	merge(ve), merge(vd) ; 
    int pte = 0, ptd = 0, tamd = vd.size(), tame = ve.size() ; 
    for(int i = 0 ; i < tam ; i++){
    	if(pte >= tame){
    		v[i] = vd[ptd] ; ptd++ ; 
    	}
    	else if(ptd >= tamd){
    		v[i] = ve[pte] ; pte++ ; 
    	}
    	else{
    		if(ve[pte] < vd[ptd]){
    			v[i] = ve[pte] ; pte++ ; 
    		}
    		else{
    			inv += (tame - pte) ; 
    			v[i] = vd[ptd] ; ptd++ ; 
    		}
    	}
    }

}

int main(){

	int n ; 
	cin >> n ; 
	
	vector<int> my ; 

	for(int i = 1, a ; i <= n ; i++){
		cin >> a ; 
		my.push_back(a) ; 
	}

	merge(my) ; 

	for(int i = 1 ; i <= n ; i++) cout << my[i] << " " ; 

	cout << inv << "\n" ; 

}
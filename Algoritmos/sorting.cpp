// o(n²) -> insertion sort 
for(int i = 1 ; i <= n ; i++){
  menor = inf ; 
  for(int j = 1 ; j <= n ; j++){
    if(!lista[v[j]] && menor > v[j]) menor = v[i] ; 
  }
  lista[menor] = 1 ; 
  cout << menor << "\n" ;
}

// o(n²) bubble sort

bool ord = 0 ; 
while(!ord){
  ord = 1 ; 
  for(int i = 1 ; i < n ; i++){
    if(v[i] > v[i+1]){
      int t = v[i] ; 
      v[i] = v[i+1], v[i+1] = t ; 
      ord = 0 ; 
    }
  }
}

// o(nlogn) merge sort 

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
    			v[i] = vd[ptd] ; ptd++ ; 
    		}
    	}
    }

}

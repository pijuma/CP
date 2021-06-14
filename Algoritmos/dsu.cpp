struct DSU{

	int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		b = find(b), a = find(a) ; 
		if(peso[a] > peso[b]) swap(a, b) ; 
		pai[a] = b ; 
		peso[b] += peso[a] ; 
	}

} dsu ; 

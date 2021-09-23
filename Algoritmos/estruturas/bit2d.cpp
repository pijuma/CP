struct BIT{

	void upd(int x, int y, int v){
		for(int i = x ; i < maxn ; i += i&-1){
			for(int j = y ; j < maxn ; j+= j&-j){
				bit[i][j] += v ; 
			}
		}
	}

	int query(int x, int y){
		int tot = 0 ; 
		for(int i = x ; i < maxn ; i += i&-1){
			for(int j = y ; j < maxn ; j+= j&-j){
				tot += bit[i][j] ; 
			}
		}
		return tot ; 
	}


} bit ; 

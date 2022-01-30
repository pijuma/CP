// soma de l a r e mudar o valor numa pos b 
#include<bits/stdc++.h>
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
#define int long long 
using namespace std ; 

const int mod = 1e9 + 7 ; 

int n, m, P, Q ;  
vector<int> sum, e, d ; 

struct SEG{

	int create(){
		sum.push_back(0) ; 
		e.push_back(0) ; 
		d.push_back(0) ; 
		return sum.size() - 1 ; 
	}

	void upd(int no, int i, int j, int pos, int v){
		
		if(i > j || i > pos) return ; 
		if(i == j && i == pos){
			sum[no] = v ;
			return ;  
		}
		
		if(no == 0) return ; 
		
		if(pos <= meio){

			if(!e[no]){
				int aux = create() ; 
				e[no] = aux ; 
			}

			upd(e[no], i, meio, pos, v) ; 
		
		}

		else{
			
			if(!d[no]){
				int aux = create() ; 
				d[no] = aux ; 
			}

			upd(d[no], meio + 1, j, pos, v) ; 
		
		}

		sum[no] = sum[e[no]] + sum[d[no]] ; 

	}

	int query(int no, int i, int j, int a, int b){
		
		if(i > b || j < a) return 0 ; 
		if(no == 0) return 0 ; 

		if(a <= i && b >= j) return sum[no] ; 

		return query(e[no], i, meio, a, b) + query(d[no], meio + 1, j, a, b) ; 

	}

} Seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> m ; 

	Seg.create() ; 
	Seg.create() ; 

	P = 91, Q = 47 ; 

	while(m--){

		char t ; 
		int a, b ; 

		cin >> t >> a >> b ; 

		if(t == '!'){
			
			a = (a+P)%n + 1 ; 
			b = (b + Q)%mod ; 
			// cout << a << " " << b << "\n" ; 
			
			Seg.upd(1, 1, n, a, b) ;

		}

		else{
			
			a = (a+P)%n + 1 ; b = (b + Q)%n + 1 ; 

			if(a > b) swap(a, b) ; 

			int z = Seg.query(1, 1, n, a, b) ; 
			
			cout << z << "\n" ; 
			
			P = ((P*31) + z)%mod ; 
			Q = ((Q*29) + z)%mod ; 
		}

	}

}

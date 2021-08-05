#include<bits/stdc++.h>

#define pii pair<int,int> 

using namespace std ; 

// separa as q abre e fecha smp q dps de uma abrindo vier uma fechando soma 1 

struct Ev{

	int x, yi, yf, t ; 

} ; 

int n, xi, xf, yi, yf, qtd ; 
vector<Ev> sw ;

bool cmp(Ev a, Ev b){ return a.x < b.x ; } // sorta x

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){

		cin >> xi >> yf >> xf >> yi ; 
		Ev ev, fv ; 
		ev.x = xi, ev.yi = yi, ev.yf = yf, ev.t = 0 ; 
		fv.x = xf, fv.yi = yi, fv.yf = yf, fv.t = 1 ; 
		sw.push_back(ev) ; sw.push_back(fv) ;

	}

	sort(sw.begin(), sw.end(), cmp) ;  
	map<int, int> mp ; 

	for(int i = 0 ; i < sw.size() ; i++){
		
		if(sw[i].t == 0){ // abre yi e yf 
			mp[sw[i].yi] = 0, mp[sw[i].yf] = 1 ; 
		}

		else{ // fechando 
			if(mp[sw[i].yi] == 0) qtd++ ; // se ngm fechou antes de mim eu n tenho ngm dentro 
			auto it = mp.find(sw[i].yi) ; // preciso passar p cara q abre antes de mim q tem quadrado dentro dele 
			--it ; 
			(*it).second = 1 ; 
			mp.erase(sw[i].yi), mp.erase(sw[i].yf) ;  
		}

	}

	cout << qtd << "\n" ;

}

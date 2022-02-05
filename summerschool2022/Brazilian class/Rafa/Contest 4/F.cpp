#include<bits/stdc++.h>
#define int long long 
using namespace std ; 


// esq começa sacando 
// se algm fizer 5pts e tiver dif maior 2 ganha o set 
// ou quem fizer 10 primeiro fecha set 
// qd printa Q numero sets, ptos atual e proximo a sacar 
// se for printar Q e tiver terminado printa numero sets(winner) - numero set 

string s ; 

int32_t main(){

	cin >> s ; 

	int turn = 0 ; // 0 - esq, 1 - dir 
	int sl = 0, sr = 0, pl = 0, pr = 0 ; 

	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'S'){
			if(turn) pr++, turn = 1 ; 
			else pl++, turn = 0 ; 
		}
		else if(s[i] == 'R') {
			if(turn) pl++, turn = 0 ; 
			else pr++, turn = 1 ; 
		}
		// cout << pl << " " << pr << "\n" ; 
		if(max(pl, pr) >= 5 && abs(pl - pr) >= 2){
			if(pl >= 5) sl++, turn = 0 ;
			else sr++, turn = 1 ; 
			pl = pr = 0 ;  
		}
		else if(max(pl, pr) >= 10){
			if(pl >= 10) sl++, turn = 0 ; 
			else sr++, turn = 1 ; 
			pl = pr = 0 ; 
		}
		if(s[i] == 'Q'){
			if(sr >= 2 || sl >= 2){
				if(sl >= 2){
					cout << sl << " (winner) - " << sr << "\n" ; 
					turn = 0 ; 
				}
				else{
					cout << sl << " - " << sr << " (winner)"<< "\n" ;
					turn = 1 ; 
				} 
			}
			else{
				if(!turn){ // esq saca
					cout << sl << " " <<  "(" << pl << "*)" << " - " << sr << " " << "(" << pr << ")\n" ; 
				}
				else cout << sl << " " <<  "(" << pl << ")" << " - " << sr << " " << "(" << pr << "*)\n" ; 
			}
		} 
	}

}

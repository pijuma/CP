#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int maxn = 1e6 + 5 ; 
const int prime = 911382323 ; 
const int prime2 = 31 ;
const int mod2 = 1e9 + 7 ;
const int mod = 972663749 ; 
 
int pot[maxn], inv[maxn], pot2[maxn], inv2[maxn] ; 
string s ; 
vector<int> normal, normal2, invert2, invert ; 
 
int exp(int a, int b){
    int ans = 1 ;
    while(b){
        if(b&1) ans = (ans*a)%mod ; 
        a = (a*a)%mod ; 
        b >>= 1 ; 
    } 
    return ans ; 
}
 
int exp2(int a, int b){
    int ans = 1 ;
    while(b){
        if(b&1) ans = (ans*a)%mod2 ; 
        a = (a*a)%mod2 ; 
        b >>= 1 ; 
    } 
    return ans ; 
}
 
void make(){
 
    pot[0] = inv[0] = 1 ; 
 
    for(int i = 1 ; i < maxn ; i++){
        pot[i] = (pot[i-1]*prime)%mod ; 
        inv[i] = exp(pot[i], mod-2) ;
    }
 
}
 
void make2(){
 
    pot2[0] = inv2[0] = 1 ; 
 
    for(int i = 1 ; i < maxn ; i++){
        pot2[i] = (pot2[i-1]*prime2)%mod2 ; 
        inv2[i] = exp2(pot2[i], mod2-2) ;
    }
 
}
 
bool tryy(int l, int r){
 
    int f = normal[r] ; 
    if(l-1 >= 0) f -= normal[l-1] ;
    f = (f+mod)%mod ; f = (f*inv[l])%mod ; 
 
    int l0 = l, r0 = r ; 
    l = s.size()-1-r0, r = s.size()-1-l0 ; 
 
    int s = invert[r] ; 
    if(l-1 >= 0) s -= invert[l-1] ;
    s = (s+mod)%mod ; s = (s*inv[l])%mod ; 
 
    return (f == s) ;
 
}
 
bool tryy2(int l, int r){
 
    int f = normal2[r] ; 
    if(l-1 >= 0) f -= normal2[l-1] ;
    f = (f+mod2)%mod2 ; f = (f*inv2[l])%mod2 ; 
 
    int l0 = l, r0 = r ; 
    l = s.size()-1-r0, r = s.size()-1-l0 ; 
 
    int s = invert2[r] ; 
    if(l-1 >= 0) s -= invert2[l-1] ;
    s = (s+mod2)%mod2 ; s = (s*inv2[l])%mod2 ; 
 
    return (f == s) ;
 
}
 
 
bool check(int tam){
 
    for(int i = 0 ; i + tam - 1 < s.size() ; i++){
        if(tryy2(i, i+tam-1) && tryy(i, i+tam-1)) return 1 ; 
    }
 
    return 0 ; 
 
}
 
vector<int> make_str(string s){
 
    vector<int> ans(s.size()+4) ;
 
    for(int i = 0 ; i < s.size() ; i++){
        if(i == 0) ans[i] = (pot[i]*(s[i]-'a'+1))%mod ;
        else ans[i] = (ans[i-1] + (pot[i]*(s[i]-'a'+1))%mod)%mod ;  
    }
 
    return ans ; 
 
}
 
vector<int> make_str2(string s){
 
    vector<int> ans(s.size()+4) ;
 
    for(int i = 0 ; i < s.size() ; i++){
        if(i == 0) ans[i] = (pot2[i]*(s[i]-'a'+1))%mod2 ;
        else ans[i] = (ans[i-1] + (pot2[i]*(s[i]-'a'+1))%mod2)%mod2 ;  
    }
 
    return ans ; 
 
}
 
int32_t main(){
 
    cin >> s ; 
 
    make() ; make2() ;
 
    normal = make_str(s) ;
    normal2 = make_str2(s) ;
    reverse(s.begin(), s.end()) ;
    invert = make_str(s) ;
    invert2 = make_str2(s) ;
    reverse(s.begin(), s.end()) ;
    
    int ini = 0, fim = s.size()/2 , mid, best = 1 ; 
 
    while(ini <= fim){
        mid = (ini + fim)>>1 ;  
        //cout << mid << "\n" ;
        if(check(2*mid + 1)){
            best = 2*mid + 1, ini = mid + 1 ;
        }  
        else{
            fim = mid - 1 ;
        } 
    }
 
    ini = 1, fim = s.size()/2 ;
 
 
    while(ini <= fim){
        mid = (ini + fim)>>1 ; 
        if(check(2*mid)){
            best = max(best, 2*mid), ini = mid + 1 ;
        }  
        else{
            fim = mid - 1 ;
        } 
    }
 
    for(int i = 0 ; i + best - 1 < s.size() ; i++){
        if(!tryy2(i, i+best-1) || !tryy(i, i+best-1)) continue ; 
        for(int j = i ; j <= i + best - 1 ; j++) cout << s[j] ; 
        cout << "\n" ; exit(0) ;
    }
 
}

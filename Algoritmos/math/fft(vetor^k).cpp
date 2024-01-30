/*
quer pegar k produtos quantos possiveis costs temos 
pode repetir o produto
  */

#include<bits/stdc++.h>
#define vb vector<bool> 
#define ll long long
#define ld double
using namespace std ; 
 
const int maxn = 1e3 + 5 ; 
const ld PI = acos(-1) ;
 
int n, m, k ;
 
struct num{
    ld a {0.0}, b {0.0};
    num(){}
    num(ld na) : a{na}{}
    num(ld na, ld nb) : a{na}, b{nb} {}
    const num operator+(const num &c) const{
        return num(a + c.a, b + c.b);
    }
    const num operator-(const num &c) const{
        return num(a - c.a, b - c.b);
    }
    const num operator*(const num &c) const{
        return num(a*c.a - b*c.b, a*c.b + b*c.a);
    }
    const num operator/(const int &c) const{
         return num(a/c, b/c);
    }
};
 
void fft(vector<num> &a, bool invert){
    int n = a.size();
    for(int i=1,j=0;i<n;i++){
        int bit = n>>1;
        for(; j&bit; bit>>=1)
            j^=bit;
        j^=bit;
        if(i<j)
            swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len <<= 1){
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        num wlen(cos(ang), sin(ang));
        for(int i=0;i<n;i+=len){
            num w(1);
            for (int j=0;j<len/2;j++){
                num u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w * wlen;
            }
        }
    }
    if(invert)
      for(num &x: a)
          x = x/n;
 
}
 
vb operator *(vb const& a, vb const& b){
    vector<num> fa(a.begin(), a.end());
    vector<num> fb(b.begin(), b.end());
    int n = 1;
    while(n < (a.size() + b.size()) )
        n <<= 1;      
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);   
    for(int i=0;i<n;i++)
        fa[i] = fa[i]*fb[i];
    fft(fa, true);
    vb result(n);
    for(int i=0;i<n;i++)
        result[i] = round(fa[i].a);
    while(result.back()==0) result.pop_back();
    return result;
}

vb check(vb a){
    for(auto b : a) if(b) b = 1 ; 
    return a ; 
}

vb exp(vb a, int b){

    vb ans ;
    ans = a ; 
    b-- ; 

    while(b){
        if(b&1){
            ans = (ans*a) ;
            ans = check(ans) ; 
        } 
        a = (a*a) ; b >>= 1 ;
        a = check(a) ; 
    }

    return ans ; 

}

int main(){
 
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    cin >> n >> k ; 

    vb f(maxn, 0) ; 

    for(int i = 1 ; i <= n ; i++){
        int a ; cin >> a ; 
        f[a]=1 ; 
    }
    
    vb vv = exp(f, k) ;

    for(int i = 0 ; i < vv.size() ; i++){
        if(vv[i]){
            cout << i << " " ; 
        }   
    }

    cout << "\n" ; 

}

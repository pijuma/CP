#include<bits/stdc++.h>
#define vi vector<int> 
#define ll long long
#define ld long double
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
const ld PI = acos(-1) ;
 
int n, m, k ;
int pass ; 

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
 
vector<ll> multiply(vi const& a, vi const& b){
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
    vector<ll> result(n);
    for(int i=0;i<n;i++)
        result[i] = round(fa[i].a);
    while(result.back()==0) result.pop_back();
    return result;
}
 
vector<ll> transform(vector<ll> &val){
    
    pass = -1 ; 

    for(int i = 0 ; i < val.size() ; i++){
        if(val[i] >= 10){
            if(i+1 >= val.size() && val[i]/10 >= 1) pass = val[i]/10 ;  
            val[i+1] += (val[i]/10) ; 
            val[i] %= 10 ; 
        }
    }

    return val ; 

}

int main(){
 
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    int t ; cin >> t ; 

    while(t--){
        string s1, s2 ; cin >> s1 >> s2 ; 
        vector<int> v1, v2 ; 
        for(auto a : s1) v1.push_back(a-'0') ; 
        for(auto a : s2) v2.push_back(a-'0') ; 
        reverse(v1.begin(), v1.end()) ; reverse(v2.begin(), v2.end()) ; 
        vector<ll> vv = multiply(v1, v2) ; 
        vv = transform(vv) ; 
        reverse(vv.begin(), vv.end()) ; 
        if(pass != -1) cout << pass ; 
        for(auto a : vv) cout << a ;
        if(vv.size() == 0 && pass == -1) cout << 0 ; 
        cout << "\n" ; 
    }
 
}

#include<bits/stdc++.h>
#define int long long 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int inf = 1e18 ;

int n, k, ans ; 
pair<int,int> tree[4*maxn] ; 
int lazy[4*maxn] ;
vector<pair<int,int>> v ; 

struct SEG{
    
    void flush(int no, int i, int j){
    
        if(!lazy[no]) return ; 
        tree[no] = {tree[no].first + ((j-i+1)*lazy[no]), tree[no].second + lazy[no]};
    
        if(i != j){
            lazy[esq] += lazy[no] ; lazy[dir] += lazy[no] ;
        }
    
        lazy[no] = 0 ;
    }
    
    void upd(int no, int i, int j, int a, int b, int val){
    
        flush(no, i, j) ;
    
        if(i > b || j < a) return ; 
        if(a <= i && b >= j){
            lazy[no] += val ;
            flush(no, i, j) ;
            return ;
        }
    
        upd(esq, i, meio, a, b, val), upd(dir, meio + 1, j, a, b, val) ;
        tree[no] = {tree[esq].first + tree[dir].first, min(tree[esq].second, tree[dir].second)} ; 
    
    }
    
    pair<int,int> query(int no, int i, int j, int a, int b){
        
        flush(no, i, j) ;
        if(i > b || j < a) return {0, inf} ;
        if(a <= i && b >= j) return tree[no] ;
        
        pair<int,int> f1 = query(esq, i , meio, a, b), f2 = query(dir, meio + 1, j, a, b) ;
        return {f1.first + f2.first, min(f2.second, f1.second)} ;
    }
    
} seg ;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second ; 
    return a.first > b.first ;
}

int32_t main(){
    
    cin >> n >> k ; 
    
    for(int i = 0 ; i < n ; i++){
        
        int x ; 
        cin >> x ; 
        
        v.push_back({x, i}) ;
        ans += x ; 
        
        if(i > 0) seg.upd(1, 0, n, i, n, 1) ;
    
    }
    
    sort(v.begin(), v.end(), cmp) ;
    seg.upd(1, 0, n, n, n, inf) ;
    
    for(int i = 0 ; i < n ; i++){
        
        int x = v[i].first, pos = v[i].second ;
        
        pair<int,int> query1, query2 ; 
        query1 = seg.query(1, 0, n, pos, pos) ;
        query2 = seg.query(1, 0, n, pos + 1, n) ;
        
        if(query1.first >= k && query2.second - k - 1 >= 0){
            ans -= x ;
            seg.upd(1, 0, n, pos, pos, -k) ;
            seg.upd(1, 0, n, pos+1, n, -k-1) ;
        }
        
    }
    
    cout << ans << "\n" ;
    
}

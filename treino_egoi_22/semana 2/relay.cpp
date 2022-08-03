// https://vjudge.net/problem/QOJ-4358 
#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
using namespace std ;

const int maxn = 2e5 + 5 ;
const int inf = 7e8 ;

int n, p[maxn], ps[maxn] ;
pair<int,int> v[maxn] ;

struct T{
    int id, id_sum, mn_sum, mn ;
};

T tree[4*maxn] ;

struct SEG{

    T join(T a, T b){
        T ans ;
        ans.mn = min(a.mn, b.mn) ;
        ans.mn_sum = min(a.mn_sum, b.mn_sum) ;
        if(a.mn > b.mn) ans.id = b.id ;
        else ans.id = a.id ;
        if(a.mn_sum > b.mn_sum) ans.id_sum = b.id_sum ;
        else ans.id_sum = a.id_sum ;
        return ans ;
    }

    void build(int no, int i, int j){
        if(i == j){
            tree[no].id = i ;
            tree[no].mn = v[i].second ;
            tree[no].mn_sum = v[i].first + v[i].second ;
            tree[no].id_sum = i ;
            return ;
        }
        build(esq, i, meio), build(dir, meio + 1, j) ;
        tree[no] = join(tree[esq], tree[dir]) ;
    }

    T query(int no, int i, int j, int l, int r){
        T null ; null.id = null.id_sum = 0 ;
        null.mn = null.mn_sum = inf ;
        if(l > j || r < i || l > r) return null ;
        if(r >= j && l <= i) return tree[no] ;
        return join(query(esq, i, meio, l, r), query(dir, meio + 1, j, l, r)) ;
    }

} Seg ;

int get_val(int i, int j, int k){return (v[i].second + v[j].second + v[k].second + v[i].first + v[j].first) ; }

int32_t main(){

    cin >> n ;

    for(int i = 1 ; i <= n ; i++){
        int a, b ; cin >> a >> b ;
        v[i] = {b, a} ;
    }

    sort(v + 1, v + 1 + n) ;

    Seg.build(1, 1, n) ;

    int ans = inf ;

    for(int j = 1 ; j <= n ; j++){
        int i = Seg.query(1, 1, n, j + 1, n).id_sum ;
        int k = Seg.query(1, 1, n, 1, j - 1).id ;
        if(i && k) ans = min(ans, get_val(i, j, k)) ;
    }

    cout << ans << "\n" ;

}

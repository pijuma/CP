#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1e3 + 10;
int a[maxn],n,x,soma,i1,i2,i3,i4;
map < int, pair< int, int>  > sum;
 
int main(void){
 
    cin >> n >> x;
 
    i1 = -1, i2 = -1, i3 = -1, i4 = -1;
 
    for( int i = 1 ; i <= n ; i++) cin >> a[i] ;
 
    for ( int i=1 ; i <= n ; i++ ){
 
        for( int j = i+1 ; j <= n; j++){
            soma = a[i] + a[j] ;
            if( soma < x && sum.find(x-soma) != sum.end() ){
                i1 = i, i2 = j;
                i3 = sum[x-soma]. first , i4 = sum[x-soma].second;
            }
        }
 
        for ( int j = 1 ; j < i ; j++){
            sum[a[i]+a[j]] = {j,i};
        }
 
    }
 
    if(i1 == -1) cout << "IMPOSSIBLE\n";
    else cout << i1 << " " <<  i2 << " " <<  i3 << " " << i4 << endl;
 
}

    #include<bits/stdc++.h>
    #define ll long long
    using namespace std ;
     
    const int mod = 1e9 + 7 ;
     
    struct Mat{
     
        int v[2][2] ;
     
        Mat (){
            for(int i = 0 ; i < 2 ; i++){
                for(int j = 0 ; j < 2 ; j++){
                    v[i][j] = 0 ;
                }
            }
        }
     
        Mat id(){
            for(int i = 0 ; i < 2 ; i++) v[i][i] = 1 ;
        }
     
        operator =(int mat[2][2]){
            for(int i = 0 ; i < 2 ; i++){
                for(int j = 0 ; j < 2 ; j++){
                    v[i][j] = mat[i][j] ;
                }
            }
         }
     
    };
     
    Mat mult(Mat &a, Mat &b){
        Mat ans ;
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                for(int k = 0 ; k < 2 ; k++){
                    ans.v[i][j] = (ans.v[i][j] + (1LL*a.v[i][k]*b.v[k][j])%mod)%mod ;
                }
            }
        }
        return ans ;
    }
     
    Mat exp(Mat a, ll b){
        Mat ans ;
        ans.id() ;
        while(b){
            if(b&1) ans = mult(ans, a) ;
            a = mult(a, a) ;
            b >>= 1 ;
        }
        return ans ;
    }
     
    int main(){
     
        ll n ;
        cin >> n ;
        if(n <= 1){
            cout << n ;
            return 0 ;
        }
        Mat a ;
        int base[2][2] = {1, 0,
                          0, 0 } ;
        a = base ;
        Mat b ;
        int aux[2][2] = {1, 1,
                         1, 0 } ;
        // aux^n-1 * base
        b = aux ;
        Mat ans ;
        b = exp(b, n-1) ;
        ans = mult(b, a) ;
        cout << ans.v[0][0] ;
     
    }

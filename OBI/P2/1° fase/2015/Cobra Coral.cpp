#include<bits/stdc++.h>
using namespace std;
int c[7],ij,i;
int main(){
    cin>>c[1]>>c[2]>>c[3]>>c[4];
    for(i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(c[i]==c[j]){
                if(abs(i-j==3)){
                  cout<<"F";
                  return 0;
                }
                else if(abs(i-j)==2){
                    cout<<"V";
                    return 0;
                }
            }
        }
    }
 }

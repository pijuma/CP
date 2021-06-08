#include<bits/stdc++.h>
using namespace std;
int x,p;
int main(){
    cin>>x;
    if(x-1-8>=0){
        cout<<x-1-8;
        return 0;
    }
    else{
        p=x-1-8;
        p=24+p;
        cout<<p;
    }
return 0;
}

//numero de caixas e de clientes
//t momento q o cliente chegou na fila em min
//d tempo necessário p ser atendido
//faz uma fila de caixas 
//assim o menor smp vai estar na 1a pos e vai ser mais usado
//sempre que for usado da pop 
//e altera o valor pegando o max entre o tempo atual ou o tempo q ele foi usado
//e soma o tempo de uso 
//sempre que o caixa tiver um tempo maior que 20 menos o tempo da entrada soma k 
#include<bits/stdc++.h>

using namespace std;
const int maxn=1e4+10;
int k, te[maxn];

int main(){
    int c,p,t,d,caixa;
    priority_queue< int,  vector<int> , greater<int> >ca;

    cin>>c>>p;

    for(int i=0;i<c;i++) ca.push(0);

    for(int i=1;i<=p;i++){
            cin>>t>>d;
            caixa=ca.top();
            ca.pop();
            if(caixa-t>20) k++;
            ca.push(max(caixa,t)+d);
    }

    cout<<k;
}

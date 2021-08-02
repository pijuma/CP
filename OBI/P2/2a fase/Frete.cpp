#include <bits/stdc++.h>
#define N 110
#define inf 1000000000


using namespace std;

vector < pair<int, int> > g[N];
int dist[N];
int n ; 

int dijkstra(int x){

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i=1 ; i<=N ; i++) dist[i] = inf;
    dist[x] = 0;
    pq.push(make_pair(0,x));

    while(!pq.empty()){

        int y = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[y]) continue;

        for(int i=0 ; i<g[y].size() ; i++){

            int v = g[y][i].first;
            int custo = g[y][i].second;

            if(dist[v] > dist[y] + custo){
                dist[v] = dist[y] + custo;
                pq.push(make_pair(dist[v], v));
            }
        }

    }
	
	return dist[n] ;

}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);

    int m;
    cin >> n >> m;

    for(int i=0 ; i<m ; i++){

        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }

    cout << dijkstra(1) << endl;

    return 0;

}

#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
  
    ll n, m, curr, ticket;
  
    cin >> n >> m;
    multiset<lli, greater<int>> tickets;
 
    while (n--)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }
 
    while (m--)
    {
        cin >> curr;
        auto it = tickets.lower_bound(curr);
        if (it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return 0;
}

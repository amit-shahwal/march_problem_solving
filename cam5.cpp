#include <bits/stdc++.h>
using namespace std;
#define fo(a, j, n) for (long long int a = j; a < n; a++)
#define foe(a, j, n) for (long long int a = j; a <= n; a++)
#define ll long long int
#define pb push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
vector<int> tt[1000000];
ll c;
ll visited[1000000];
queue<ll> q;
void bfs(int source)
{  
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {   c++;
        int curr = q.front();
        q.pop();
        fo(i, 0, tt[curr].size())
        {
            if (visited[tt[curr][i]] == 0)
            {
                visited[tt[curr][i]] = 1;
                q.push(tt[curr][i]);
            }
        }
    }
}
int main()
{   
    ll t;
    cin >> t;
    while (t--)
    {   ll count=0;
        ll peers;
        cin >> peers;
        ll n, x, y;
        cin >> n;
        fo(i, 0, n)
        {
            cin >> x;
            cin >> y;
            tt[x].pb(y);
            tt[y].pb(x);
        }
        fo(i, 0, peers)
        {
            if (visited[i] == 0)
            {
                count++;
                bfs(i);
            }
        }
    cout << count << endl;
    memset(tt, 0, sizeof(tt));
     memset(visited, 0, sizeof(visited));
    }
}
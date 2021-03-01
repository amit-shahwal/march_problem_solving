#include <bits/stdc++.h>
using namespace std;
#define fo(a, j, n) for (long long int a = j; a < n; a++)
#define foe(a, j, n) for (long long int a = j; a <= n; a++)
#define ll long long int
#define pb push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
ll visited[1000000];
vector<int> tt[1000000];
queue<ll> q;
void bfs(int source)
{
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {
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
   
    
        ll count = 0;
        int n, m, x, y;
        cin >> n >> m;
        if (n <= m)
        {
            cout << "NO";
        }
        else
        {
            fo(i, 0, m)
            {
                cin >> x >> y;
                tt[x-1].pb(y-1);
               
            }

            fo(i, 0, n)
            {
                if (visited[i] == 0)
                {
                    count++;
                 
                    bfs(i);
                }
            }
            if (count == 1 && n==m+1)
                cout << "YES";
            else
                cout << "NO";
        }
       
    
}
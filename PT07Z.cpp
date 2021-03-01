#include <bits/stdc++.h>
using namespace std;
#define fo(a, j, n) for (long long int a = j; a < n; a++)
#define foe(a, j, n) for (long long int a = j; a <= n; a++)
#define ll long long int
#define pb push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
int dsitance[1000000];
int visited[1000000];
vector<int> t[1000000];
void dfs(int source)
{
    visited[source] = 1;
    fo(i, 0, t[source].size())
    {
        if (visited[t[source][i]] == 0)
        {
            int p = t[source][i];

            dsitance[p] = dsitance[source] + 1;
            dfs(p);
        }
    }
}
int main()
{
    int n, x, y; // n nodes
    cin >> n;
    fo(i, 0, n-1)
    {
        cin >> x;
        cin >> y;
        t[x - 1].pb(y - 1);
        t[y - 1].pb(x - 1);
    }
    fo(i, 0, n-1)
    {
        if (visited[i] == 0)
            dfs(i);
    }
    int maxElementIndex = max_element(dsitance, dsitance + n) - dsitance;
    memset(dsitance, 0, sizeof(dsitance));
    memset(visited, 0, sizeof(visited));

    dfs(maxElementIndex);

    cout << *max_element(dsitance, dsitance + n);
}
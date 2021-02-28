#include <bits/stdc++.h>
using namespace std;
#define fo(a, j, n) for (long long int a = j; a < n; a++)
#define foe(a, j, n) for (long long int a = j; a <= n; a++)
#define ll long long int
#define pb push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
int visited[5];
vector<int> t[5];
void dfs(int source)
{
    cout << source << endl;
    visited[source] = 1;
    fo(i, 0, t[source].size())
    {
        if (visited[t[source][i]] == 0)
        {
            dfs(t[source][i]);
        }
    }
}
int main()
{
    memset(visited, 0, sizeof(visited));
    int n, x, y;

    cin >> n;
    fo(i, 0, n)
    {
        cin >> x;
        cin >> y;
        t[x].push_back(y);
    }
    for (int i = 0; i < n; i++)
    {

        if (visited[i] == 0)
        {

            dfs(i);
        }
    }
}
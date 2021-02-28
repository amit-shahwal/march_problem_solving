#include <bits/stdc++.h>
using namespace std;
#define fo(a, j, n) for (long long int a = j; a < n; a++)
#define foe(a, j, n) for (long long int a = j; a <= n; a++)
#define ll long long int
#define pb push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
vector<int> t[5];
vector<int> ans;
queue<int> q;
int visited[5];
void bfs(int n)
{
    q.push(n);

    while (!q.empty())
    {
        int p = q.front();
        ans.push_back(p);
        q.pop();

        fo(i, 0, t[p].size())
        {
            if (visited[t[p][i]] == -1)
            {
                q.push(t[p][i]);
                visited[t[p][i]] = 1;
            }
        }
    }
}
int main()
{
    memset(visited, -1, sizeof(visited));
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

        if (visited[i] == -1)
        {
            visited[i] = 1;
            bfs(i);
        }
    }
    fo(i,0,n)
    cout<<ans[i]<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define fo(a, j, n) for (long long int a = j; a < n; a++)
#define foe(a, j, n) for (long long int a = j; a <= n; a++)
#define ll long long int
#define pb push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
map<string, int> mp;
int subString(string s, int n)
{   int count = 0;

    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
        {
            string str;
            str += s.substr(i, len);
            sort(str.begin(), str.end());
            mp[str]++;
        }
        for(auto it = mp.begin(); it != mp.end();it++)
        {
            int k=it->second;
            int p=k*(k-1)/2;
            count+=p;
        }
        return count;
}

int main()
{

    cout<<subString("abba", 4);
}
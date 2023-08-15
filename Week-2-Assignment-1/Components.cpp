#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int dfs(int s)
{
    visited[s] = 1;
    int cnt = 1;
    for (int v : adj[s])
    {
        if (!visited[v])
        {
            cnt += dfs(v);
        }
    }
    return cnt;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int val = dfs(i);

            if (val > 1)
            {
                result.push_back(val);
            }
        }
    }
    sort(result.begin(), result.end());

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}

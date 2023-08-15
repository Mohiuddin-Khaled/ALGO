#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l;
    cin >> l;

    vector<int> shop;
    vector<bool> visited(n, false);

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        int u = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level == l)
        {
            shop.push_back(u);
        }
        else if (level > l)
        {
            break;
        }

        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push({v, level + 1});
                visited[v] = true;
            }
        }
    }

    if (shop.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        sort(shop.begin(), shop.end());

        for (int i : shop)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

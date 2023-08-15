#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e3 + 5;

vector<int> adjList[N];

int bfs(int s, int d)
{
    queue<pair<int, int>> q;
    q.push({s, 0});
    vector<bool> visited(N, false);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front().first;
        int len = q.front().second;
        q.pop();

        if (u == d)
        {
            return len;
        }

        for (int v : adjList[u])
        {
            if (!visited[v])
            {
                q.push({v, len + 1});
                visited[v] = true;
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int s, d;
        cin >> s >> d;
        cout << bfs(s, d) << "\n";
    }

    return 0;
}

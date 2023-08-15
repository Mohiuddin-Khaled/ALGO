#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    int K;
    cin >> K;
    visited[K] = 1;
    queue<int> q;
    q.push(K);
    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}

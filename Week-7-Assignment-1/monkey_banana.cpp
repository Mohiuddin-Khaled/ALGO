// problem link: https://lightoj.com/problem/monkey-banana-problem

// memoization
#include <bits/stdc++.h>
using namespace std;

const int MAX = 205;

int n, N;
vector<vector<int>> value;
long long dp[MAX][MAX];

long long solve(int i, int j)
{
    // base case
    if (i == N - 1)
        return value[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    long long ans;

    if (i < n - 1)
    {
        // upper half: move down or down-right
        ans = value[i][j] + max(
                                solve(i + 1, j),
                                solve(i + 1, j + 1));
    }
    else
    {
        long long op1 = LLONG_MIN;
        long long op2 = LLONG_MIN;

        // move down (i+1, j)
        if (j < value[i + 1].size())
            op1 = solve(i + 1, j);

        // move down-left (i+1, j-1)
        if (j - 1 >= 0)
            op2 = solve(i + 1, j - 1);

        ans = value[i][j] + max(op1, op2);
    }

    return dp[i][j] = ans;
}

int main()
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        N = 2 * n - 1;

        value.assign(N, vector<int>());

        // upper half
        for (int i = 0; i < n; i++)
        {
            value[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
                cin >> value[i][j];
        }

        // lower half
        for (int i = n; i < N; i++)
        {
            int sz = N - i;
            value[i].resize(sz);
            for (int j = 0; j < sz; j++)
                cin >> value[i][j];
        }

        memset(dp, -1, sizeof(dp));

        cout << "Case " << tc << ": " << solve(0, 0) << endl;
    }

    return 0;
}

// tabulation
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;

        int N = 2 * n - 1;

        vector<vector<int>> value(N);
        vector<vector<int>> dp(N);

        // upper half
        for (int i = 0; i < n; i++)
        {
            value[i].resize(i + 1);
            dp[i].resize(i + 1);

            for (int j = 0; j <= i; j++)
            {
                cin >> value[i][j];
            }
        }

        // lower half
        for (int i = n; i < N; i++)
        {
            int sz = N - i;
            value[i].resize(sz);
            dp[i].resize(sz);

            for (int j = 0; j < sz; j++)
            {
                cin >> value[i][j];
            }
        }

        // initialize
        dp[0][0] = value[0][0];

        // upper half DP
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + value[i][j];
                else if (j == i)
                    dp[i][j] = dp[i - 1][j - 1] + value[i][j];
                else
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + value[i][j];
            }
        }

        // lower half DP
        for (int i = n; i < N; i++)
        {
            for (int j = 0; j < (int)value[i].size(); j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + value[i][j];
            }
        }

        cout << "Case " << tc << ": " << dp[N - 1][0] << endl;
    }

    return 0;
}
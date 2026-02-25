// problem link: https://atcoder.jp/contests/dp/tasks/dp_a
// solving with memoization

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrence: stone(n) = min (
                    stone(n - 1) + abs(h[n] - h[n-1])
                    stone(n - 2) + abs(h[n] - h[n-2])
                )
- base case: stone(1) = 0
*/

int h[N], dp[N];

int stone(int n)
{
    // 1. base case
    if (n == 1)
        return 0;

    // 2. check if answer already exists
    if (dp[n] != -1)
        return dp[n];

    // 3. calculate answer from sub-problem
    int ans1 = stone(n - 1) + abs(h[n] - h[n - 1]); // n = 2 => n - 1 = 1

    // edge case or corner case
    if (n == 2)
        return dp[n] = ans1;

    int ans2 = stone(n - 2) + abs(h[n] - h[n - 2]); // n = 2 => n - 2 = 0

    return dp[n] = min(ans1, ans2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++)
        dp[i] = -1;

    // memset(dp, -1, sizeof(dp));

    cout << stone(n) << endl;
    return 0;
}
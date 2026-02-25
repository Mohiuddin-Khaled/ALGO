// problem link: https://cses.fi/problemset/task/1637/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> dp(N, INT_MAX);

int digit(int n)
{
    if (n == 0)
        return 0;
    if (dp[n] != INT_MAX)
        return dp[n];
    vector<int> dg;
    for (char c : to_string(n))
    {
        dg.push_back(c - '0');
    }
    for (int val : dg)
    {
        dp[n] = min(dp[n], digit(n - val) + 1);
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << digit(n);
    return 0;
}
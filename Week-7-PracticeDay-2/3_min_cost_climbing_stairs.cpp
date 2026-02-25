// problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

// memoization method
#include <bits/stdc++.h>
using namespace std;

/*
    - dp state: dp(n) = minimum cost to reach stair n
    - recurrence: dp(n) = cost[n] + min(dp(n-1), dp(n-2))
    - base case: dp(0) = cost[0]
                 dp(1) = cost[1]
*/

class Solution
{
public:
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {
        // base case
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];
        // if answer is already calculated return it
        if (dp[n] != -1)
            return dp[n];
        // recurrence
        return dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

// tabulation

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

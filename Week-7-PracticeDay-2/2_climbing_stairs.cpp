// problem link: https://leetcode.com/problems/climbing-stairs/
// climbing stairs

/*
    - dp state: dp(n) = number of distinct way to reach the n-th stairs
    - recurrence:  dp(n) = dp(n - 1) + dp(n - 2)
    - base case: dp(1) = 1
                 dp(2) = 2
*/

#include <bits/stdc++.h>
using namespace std;

// memoization

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// time complexity: O(n)
// space complexity: O(n)

// tabulation
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        if (n <= 2)
            return n;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

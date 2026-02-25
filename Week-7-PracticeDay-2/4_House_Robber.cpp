// problem link: https://leetcode.com/problems/house-robber/

/*
 - dp state: dp[i] = maximum money that can be robbed up to house i

 - recurrence: dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

 - base case: dp[0] = nums[0]
              dp[1] = max(nums[0], nums[1])
*/
#include <bits/stdc++.h>
using namespace std;

// memoization method
class Solution
{
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n == 0)
            return nums[0];
        if (n == 1)
            return max(nums[0], nums[1]);
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = max(
                   solve(nums, n - 1, dp),          // skip current house
                   nums[n] + solve(nums, n - 2, dp) // rob current house
               );
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, n - 1, dp);
    }
};

// iterative method
/*
 - dp state: dp[i] = maximum money that can be robbed up to house i

 - recurrence: dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

 - base case: dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        if (n == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
// problem link: https://www.spoj.com/problems/FARIDA/en/

/*
 - dp state: dp[i] = maximum coins collected up to monster i

 - recurrence: dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

 - base case: dp[0] = nums[0]
              dp[1] = max(nums[0], nums[1])
*/

// memoization

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> &nums, ll n, vector<ll> &dp)
{
    if (n == 0)
        return nums[0];

    if (n == 1)
        return max(nums[0], nums[1]);

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = max(
               solve(nums, n - 1, dp),          // skip current monster
               nums[n] + solve(nums, n - 2, dp) // collect current monster's coins
           );
}

ll collectCoins(vector<ll> &nums)
{
    ll n = nums.size();

    if (n == 0)
        return 0; // handle empty case
    if (n == 1)
        return nums[0]; // single monster case

    vector<ll> dp(n, -1);
    return solve(nums, n - 1, dp);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll n;
        cin >> n;
        vector<ll> nums(n);
        for (int j = 0; j < n; j++)
        {
            cin >> nums[j];
        }
        cout << "Case " << i << ": " << collectCoins(nums) << endl;
    }
    return 0;
}

// tabulation
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// ll collectCoins(vector<ll> &nums)
// {
//     int n = nums.size();
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return nums[0];
//     vector<ll> dp(n, 0);
//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);
//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//     }
//     return dp[n - 1];
// }

// int main()
// {
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         int n;
//         cin >> n;
//         vector<long long> nums(n);
//         for (int i = 0; i < n; i++)
//             cin >> nums[i];
//         cout << "Case " << i << ": " << collectCoins(nums) << endl;
//     }
//     return 0;
// }

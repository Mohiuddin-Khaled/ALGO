// problem link: https://www.spoj.com/problems/RPLB/en/
// memoization dp
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// ll dp[1005][1005];

// ll solve(vector<ll> &nums, int i, ll limit)
// {
//     if (i >= nums.size())
//         return 0;

//     if (dp[i][limit] != -1)
//         return dp[i][limit];

// skip current
//     ll skip = solve(nums, i + 1, limit);

// if possible take current
//     ll take = 0;
//     if (nums[i] <= limit)
//         take = nums[i] + solve(nums, i + 2, limit - nums[i]);

//     return dp[i][limit] = max(skip, take);
// }

// int main()
// {
//     int t;
//     cin >> t;
//     for (int test = 1; test <= t; test++)
//     {
//         int n;
//         ll k;
//         cin >> n >> k;

//         vector<ll> nums(n);
//         for (int i = 0; i < n; i++)
//             cin >> nums[i];

//         memset(dp, -1, sizeof(dp));

//         cout << "Scenario #" << test << ": " << solve(nums, 0, k) << endl;
//     }
//     return 0;
// }

// dp tabulation
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1005][1005];

int main()
{
    int t;
    cin >> t;

    for (int test = 1; test <= t; test++)
    {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        // Initialize DP
        for (int i = 0; i <= n + 2; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 0;

        // Build bottom-up
        for (int i = n - 1; i >= 0; i--)
        {
            for (int limit = 0; limit <= k; limit++)
            {
                // skip
                ll skip = dp[i + 1][limit];

                // take
                ll take = 0;
                if (nums[i] <= limit)
                    take = nums[i] + dp[i + 2][limit - nums[i]];

                dp[i][limit] = max(skip, take);
            }
        }

        cout << "Scenario #" << test << ": " << dp[0][k] << endl;
    }
    return 0;
}
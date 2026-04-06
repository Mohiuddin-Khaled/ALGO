// problem link: https://codeforces.com/contest/456/problem/C

/*
    [5, 3, 5, 3, 4]

    values → 3, 4, 5

    3 → 2 times → 6 points
    4 → 1 time  → 4 points
    5 → 2 times → 10 points

    Value:   3   4   5
    Points:  6   4   10

    dp[3] = 6
    dp[4] = max(6, 4) = 6
    dp[5] = max(6, 6 + 10) = 16
*/

// // memoization
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// const int N = 1e5 + 5;

// class Solution
// {
// public:
//     vector<ll> cnt;
//     vector<ll> dp;

//     ll solve(int i)
//     {
//         // base cases
//         if (i == 0)
//             return 0;
//         if (i == 1)
//             return cnt[1] * 1;

//         // if answer is already calculated
//         if (dp[i] != -1)
//             return dp[i];

//         // calculated the answer smaller sub problems
//         ll skip = solve(i - 1);
//         ll take = solve(i - 2) + cnt[i] * i;

//         return dp[i] = max(skip, take);
//     }

//     ll Boredom(vector<int> &nums)
//     {
//         cnt.assign(N + 1, 0);
//         dp.assign(N + 1, -1);

//         // frequency
//         for (int x : nums)
//             cnt[x]++;

//         return solve(N);
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> nums(n);
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];

//     Solution obj;
//     cout << obj.Boredom(nums) << endl;

//     return 0;
// }

// iterative / tabulation

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

class Solution
{
public:
    long long Boredom(vector<int> &nums)
    {
        // frequency array
        vector<long long> cnt(N + 1, 0);

        for (int x : nums)
            cnt[x]++;

        // dp array
        vector<long long> dp(N + 1, 0);

        // base case
        dp[1] = cnt[1] * 1;

        // calculated the answer from smaller sub problems
        for (int i = 2; i <= N; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);

        return dp[N];
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    cout << obj.Boredom(nums) << endl;

    return 0;
}

// problem link: https://atcoder.jp/contests/dp/tasks/dp_c
// Tabulation

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

/*
 - state: dp[day][task] = maximum happiness till day-n
                          if we pick task-x on that day-n

 - iterative: dp[day][task] = max(dp[day - 1][current_task]) + happiness[day][task]
                               where current_task != task

 - base case: dp[1][task] = happiness[1][task]
*/

int happiness[N][4], dp[N][4];

int main()
{
    int n;
    cin >> n;
    for (int day = 1; day <= n; day++)
    {
        for (int task = 1; task <= 3; task++)
        {
            cin >> happiness[day][task];
        }
    }
    // 1. handle base case
    for (int task = 1; task <= 3; task++)
    {
        dp[1][task] = happiness[1][task];
    }
    // 2. loop over the sates
    for (int day = 2; day <= n; day++)
    {
        for (int task = 1; task <= 3; task++)
        {
            // 3. calculate the answer from smaller sub - problems
            dp[day][task] = 0;
            for (int current_task = 1; current_task <= 3; current_task++)
            {
                if (current_task != task)
                {
                    dp[day][task] = max(
                        dp[day][task],
                        dp[day - 1][current_task] + happiness[day][task]);
                }
            }
        }
    }
    int ans = max({dp[n][1], dp[n][2], dp[n][3]});
    cout << ans << endl;
    return 0;
}

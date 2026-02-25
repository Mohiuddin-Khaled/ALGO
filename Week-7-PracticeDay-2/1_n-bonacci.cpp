// time complexity: O(n)
// space complexity: O(n)

// memoization
#include <bits/stdc++.h>
using namespace std;
const int N = 101;

/*
 - bonacci(n) -> calculate the n-th bonacci number
 - bonacci(n) = bonacci(n−1) + bonacci(n−2) + bonacci(n−3) + bonacci(n - 4)
 - bonacci(1) = 1, bonacci(2) = 1, bonacci(3) = 1, bonacci(4) = 1
*/

int dp[N];         // dp array
int bonacci(int n) // state
{
    // base case
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 1;
    if (n == 4)
        return 1;
    if (n <= 4)
        return 1;
    // check if current state is already solved, return the result
    if (dp[n] != -1)
        return dp[n];
    // calculate the result from smaller sub-problem
    int ans = bonacci(n - 1) + bonacci(n - 2) + bonacci(n - 3) + bonacci(n - 4);
    return dp[n] = ans; // Ex. n = 6 | dp[6] = bonacci(5) + bonacci(4) + bonacci(3) + bonacci(2)
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = -1; // mark all state as unvisited
    // / memset(dp, -1, sizeof(dp));
    cout << bonacci(n) << endl;
    return 0;
}

// tabulation method
#include <bits/stdc++.h>
using namespace std;
const int N = 101;

/*
  - bonacci(n) -> calculate the n-th bonacci number
  - bonacci(n) = bonacci(n - 1) + bonacci(n - 2) + bonacci(n - 3) + bonacci(n - 4)
  - bonacci(1) = 1, bonacci(2) = 1, bonacci(3) = 1, bonacci(4) = 1
*/

int dp[N];

int main()
{
    int n;
    cin >> n;

    // base case
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;

    // loop through the state
    for (int i = 5; i <= n; i++)
    {
        // calculate the answer from smaller sub-problems
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    cout << dp[n] << endl;
    return 0;
}
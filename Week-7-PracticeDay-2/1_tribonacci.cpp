// time complexity: O(n)
// space complexity: O(n)

// memoization
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 101;
/*
 - fib(n) -> calculate the n-th fibonacci number
 - fib(n) = fib(n−1) + fib(n−2) + fib(n−3)
 - fib(1) = 1, fib(2) = 1, fib(3) = 1
*/
// int dp[N]; // dp array
// int fib(int n) // state
// {
// base case
// if(n == 1) return 1;
// if(n == 2) return 1;
// if(n == 3) return 1;
// if (n <= 3)
//     return 1;
// check if current state is already solved, return the result
// if (dp[n] != -1)
//     return dp[n];
// calculate the result from smaller sub-problem
// int ans = fib(n - 1) + fib(n - 2) + fib(n - 3);
// return dp[n] = ans; // Ex. n = 6 | dp[6] = fib(5) + fib(4) + fib(3)
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         dp[i] = -1; // mark all state as unvisited
//     / memset(dp, -1, sizeof(dp));
//     cout << fib(n) << endl;
//     return 0;
// }

// tabulation method
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 101;
/*
  - fib(n) -> calculate the n-th fibonacci number
  - fib(n) = fib(n - 1) + fib(n - 2) + fib(n - 3)
  - fib(1) = 1, fib(2) = 1, fib(3) = 1
*/
// int dp[N];
// int main()
// {
//     int n;
//     cin >> n;
//     / 1. base case
//     dp[1] = 1;
//     dp[2] = 1;
//     dp[3] = 1;
//     / 2. loop through the state
//     for (int i = 4; i <= n; i++)
//     {
//         / 3. calculate the answer from smaller sub-problems
//         dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//     }
//     cout << dp[n] << endl;
//     return 0;
// }
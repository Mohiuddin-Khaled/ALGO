#include <bits/stdc++.h>
using namespace std;
const int N = 101;

/*
 - fib(n) -> calculate the n-th fibonacci number
 - fib(n) = fib(n - 1) + fib(n - 2)
 - fib(1) = 1, fib(2) = 1
*/

int dp[N]; // dp array

int fib(int n) // state
{
    // base case
    // if(n == 1) return 1;
    // if(n == 2) return 1;
    if (n <= 2)
        return 1;
    // check if current state is already solved, return the result
    if (dp[n] != -1)
    {
        return dp[n];
    }
    // calculate the result from smaller sub-problem
    int ans = fib(n - 1) + fib(n - 2);
    dp[n] = ans; // Ex. n = 5 | dp[6] = fib(5) + fib(4)
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1; // mark all state as unvisited
    }
    // memset(dp, -1, sizeof(dp));
    cout << fib(n) << endl;
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

long long ara[101];

long long fib(int n)
{
    if (n <= 2)
        return 1;
    // check if fib(n) is already calculated
    if (ara[n] != 0)
        return ara[n];
    ara[n] = fib(n - 1) + fib(n - 2);
    return ara[n];
}

int main()
{
    cout << fib(3) << endl;
    cout << fib(5) << endl;
    cout << fib(50) << endl;
    return 0;
}
// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(3) << endl;
    cout << fib(5) << endl;
    cout << fib(50) << endl;
    return 0;
}

/*
    int fun(int n)
    {
        if (n <= 2) return 1;
        return fun(n - 1);
    }
*/

/*
    int fib(int n)
    {
        if (n <= 2) return 1;
        return fib(n - 1) + fib(n - 2);
    }
*/

// find sum of numbers array (Recursion)
// general form: sum(n) = sum(n - 1) + n
// int sum(int n)
// {
//     if(n == 0)
//         return 0;
//     else
//         return n + sum(n - 1);
// }

// find fibonacci series (Recursion)
// general form: fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
// base case: n = 0 or n = 1 then fibonacci(n) = 1

// int fibonacci(int n)
// {
//     if (n == 0 || n == 1)
//         return 1;
//     else
//         return fibonacci(n - 1) + fibonacci(n - 2);
// }

// find fibonacci series (Dynamic Programming) => Recursion + Memoization
// int ar[n];
// int fibonacci(int n)
// {
//     if (n == 0 || n == 1)
//         return 1;
//     else if (ar[n] == 0)
//         ar[n] = fibonacci(n - 1) + fibonacci(n - 2);
//     return ar[n];
// }

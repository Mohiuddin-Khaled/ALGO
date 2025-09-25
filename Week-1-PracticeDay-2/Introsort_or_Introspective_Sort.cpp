// Introsort
// Introspective sort
// hybrid sort
// combine to sorting algorithm(heap sort, merge sort, quick sort)
// Developed by David Musser 1997
// complexity O(nlogn)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    for (int i : ar)
    {
        cout << i << " ";
    }
    return 0;
}
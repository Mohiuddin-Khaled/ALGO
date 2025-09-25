// complexity O(nlogn)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    // input array
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    // selection sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                swap(ar[i], ar[j]);
            }
        }
    }
    // output array
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}
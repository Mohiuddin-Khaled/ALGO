#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, value, mid;
    cin >> n >> value;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    bool flag;
    int l = 0, h = n - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == value)
        {
            flag = true;
            break;
        }
        else if (arr[mid] < value)
            l = mid + 1;
        else
            h = mid - 1;
    }
    cout << (flag ? "found" : "not found") << endl;
    return 0;
}
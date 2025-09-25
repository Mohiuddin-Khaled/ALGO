#include <bits/stdc++.h>
using namespace std;
int findSecondLargest(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    if (arr.size() < 2)
    {
        return -1;
    }
    else
    {
        return arr[arr.size() - 2];
    }
}
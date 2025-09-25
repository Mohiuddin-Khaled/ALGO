#include <bits/stdc++.h>
using namespace std;

void conquer(int l, int r, int mid, vector<int> &arr)
{
    int left_side = mid - l + 1, right_side = r - mid;
    vector<int> left_ar(left_side + 1), right_ar(right_side + 1);
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        left_ar[j] = arr[i];
    }
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        right_ar[j] = arr[i];
    }
    left_ar[left_side] = INT_MAX, right_ar[right_side] = INT_MAX;
    int left_pointer = 0, right_pointer = 0;
    for (int i = l; i <= r; i++)
    {
        if (left_ar[left_pointer] <= right_ar[right_pointer])
        {
            arr[i] = left_ar[left_pointer++];
        }
        else
        {
            arr[i] = right_ar[right_pointer++];
        }
    }
}

void divide(int l, int r, vector<int> &arr)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    divide(l, mid, arr);
    divide(mid + 1, r, arr);
    conquer(l, r, mid, arr);
}

void mergeSort(vector<int> &arr, int n)
{
    divide(0, n - 1, arr);
}
// complexity O(n log n)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];

// conquer
void mergeArray(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int L[left_size + 1];
    int right_size = r - mid;
    int R[right_size + 1];
    // fill left array value
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = nums[i];
    }
    // fill right array value
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = nums[i];
    }
    // Infinity
    L[left_size] = INT_MAX;
    R[right_size] = INT_MAX;
    // merge two array
    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }
}

// Divide
void mergeSort(int l, int r)
{
    if (l >= r) // base case
        return;

    int mid = (l + r) / 2;
    // left half array
    mergeSort(l, mid);
    // right half array
    mergeSort(mid + 1, r);
    // conquer
    mergeArray(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}

class Solution
{
public:
    // conquer
    void mergeSort(int l, int r, int mid, vector<int> &nums)
    {
        int left_size = mid - l + 1;
        int right_size = r - mid;
        vector<int> Left(left_size + 1);
        vector<int> Right(right_size + 1);
        for (int i = l, j = 0; i <= mid; i++, j++)
        {
            Left[j] = nums[i];
        }
        for (int i = mid + 1, j = 0; i <= r; i++, j++)
        {
            Right[j] = nums[i];
        }
        Left[left_size] = INT_MAX;
        Right[right_size] = INT_MAX;
        int lp = 0, rp = 0;
        for (int i = l; i <= r; i++)
        {
            if (Left[lp] <= Right[rp])
            {
                nums[i] = Left[lp++];
            }
            else
            {
                nums[i] = Right[rp++];
            }
        }
    }
    // divide
    void merge(int l, int r, vector<int> &nums)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        merge(l, mid, nums);
        merge(mid + 1, r, nums);
        mergeSort(l, r, mid, nums);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        merge(0, nums.size() - 1, nums);
        return nums;
    }
};
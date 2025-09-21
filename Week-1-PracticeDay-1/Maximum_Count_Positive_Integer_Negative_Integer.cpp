class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pcnt = 0, ncnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                pcnt++;
            else if (nums[i] < 0)
                ncnt++;
        }
        return max(pcnt, ncnt);
    }
};
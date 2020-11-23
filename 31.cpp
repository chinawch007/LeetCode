class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)return;

        bool flag = false;
        for(int i = len-1; i > 0; --i)
        {
            if(nums[i] > nums[i-1])
            {
                int j;
                for(j = len-1; j > i-1; --j)
                {
                    if(nums[j] > nums[i-1])break;
                }
                swap(nums[i-1], nums[j]);
                sort(nums.begin()+i, nums.end());
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            for(int i = 0; i <= len/2-1; i++)
            {
                swap(nums[i], nums[len-1-i]);
            }
        }
    }
};
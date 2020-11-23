class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();

        int sum = 0;
        int maxl = 0;
        m[0] = len;
        for(int i = len-1; i >= 0; --i)
        {
             sum += nums[i];

            if(m.find(sum-k) != m.end())
            {
                if(m[sum-k]-i > maxl)maxl = m[sum-k] - i;
            }

            if(m.find(sum) == m.end())
            {
                m[sum] = i;
            }
        }

        return maxl;
    }

    map<int, int> m;
};
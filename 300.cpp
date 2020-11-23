class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)return 0;
        vector<int> p;
        int* dp = new int[len];

        p.push_back(nums[0]);
        dp[0] = 1;
        int ma = 1;

        for(int i = 1; i < len; ++i)
        {
            auto iter = lower_bound(p.begin(), p.end(), nums[i]);
            if(iter == p.end())
            {
                dp[i] = p.size() + 1;
                if(dp[i] > ma)ma = dp[i];
                p.push_back(nums[i]);
            }
            else
            {
                dp[i] = iter - p.begin() + 1;
                if(dp[i] > ma)ma = dp[i];
                *iter = nums[i];
            }
        }

        return ma;
    }
};
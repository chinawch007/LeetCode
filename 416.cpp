class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; ++i)sum += nums[i];
        if(sum%2 == 1)return false;
        sum /= 2;

        bool dp[20001];
        dp[0] = true;
        for(int i = 1; i <= sum; ++i)dp[i] = false;
        for(int i = 0; i < len; ++i)
        {
            for(int j = sum; j >= nums[i]; --j)
            {
                if(dp[j-nums[i]])dp[j] = true;
            }
        }
        
        return dp[sum];
    }
};s
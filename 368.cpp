//又快速筛出整除数的数吗
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int sz = nums.size();
        
        int* dp = new int[sz];
        int* link = new int[sz];
        
        int maxv = 0, maxi = 0;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz; ++i)
        {
            dp[i] = 1;
            link[i] = -1;
            
            for(int j = i-1; j >= 0; --j)
            {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    link[i] = j;
                }
            }
            
            if(dp[i] > maxv)
            {
                maxv = dp[i];
                maxi = i;
            }
        }
        
        int* res = new int[maxv];
        for(int i = maxi, j = maxv-1; i != -1 && j >= 0; i = link[i], --j)
        {
            res[j] = nums[i];
        }
        
        vector<int> ret;
        for(int i = 0; i < maxv; ++i)
            ret.push_back(res[i]);
        
        return ret;
    }
};

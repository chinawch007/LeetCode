class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        
        vector<int> num;
        num.push_back(1);
        for(int i = 0; i < n; ++i)
        {
            num.push_back(nums[i]);
        }
        num.push_back(1);
        
        int** dp = new int*[n+2];
        for(int i = 0; i <= n+1; ++i)
            dp[i] = new int[n+2];
        
        for(int i = 1; i <= n; ++i)
        {
            dp[i][i] = num[i] * num[i-1] * num[i+1];
        }
        
        for(int l = 2; l <= n; ++l)
        {
            for(int i = 1; i+l-1 <= n; ++i)
            {
                dp[i][i+l-1] = 0;
                
                for(int j = i; j <= i+l-1; ++j)
                {
                    int tmp = (j-1>=i ? dp[i][j-1] : 0) + (j+1<=i+l-1 ? dp[j+1][i+l-1] : 0) + num[j]*num[i-1]*num[i+l];
                    if(tmp > dp[i][i+l-1])dp[i][i+l-1] = tmp;
                }
            }
        }
        
        return dp[1][n];
    }
};

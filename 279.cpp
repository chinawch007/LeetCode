class Solution {
public:
    int numSquares(int n) {
        int sz = (int)(sqrt(n));
        
        int* dp = new int[n+1];
        int* sqt = new int[sz+1];
        
        for(int i = 1; i <= sz; ++i)
        {
            sqt[i] = i*i;
        }
        
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = INT32_MAX;   
        }
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= sz; ++j)
            {
                if(i - sqt[j] < 0)break;
                if(dp[i-sqt[j]] + 1 < dp[i])dp[i] = dp[i-sqt[j]] + 1;
            }
        }
        
        return dp[n];
    }
};

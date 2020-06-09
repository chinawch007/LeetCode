//copy也算作一次操作
class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        
        bool su[1001];
        int dp[1001];
        
        for(int i = 2; i <= 1000; ++i)
        {
            su[i] = true;
            dp[i] = i;
        }
        
        for(int i = 2; i <= 1000; ++i)
        {
            for(int j = 2; j <= 1000; ++j)
            {
                if(i*j>1000)break;
                su[i*j] = false;
            }
        }
        
        if(su[n])return n;
        
        int ret = n;
        
        for(int i = 2; i <= n; ++i)
        {
            if(su[i])dp[i] = i;
            else
            {
                int jend = (int)sqrt(i);
                for(int j = 2; j <= jend; ++j)
                {
                    if(i%j == 0)
                    {
                        if(dp[j] + i/j < dp[i])
                            dp[i] = dp[j] + i/j;
                        if(dp[i/j] + j < dp[i])
                            dp[i] = dp[i/j] + j;
                    }
                }
            }
            cout << i << ":" << dp[i] << endl;
        }
        
        return dp[n];
    }
};

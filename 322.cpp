class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();

        int dp[20001];
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)dp[i] = -1;
        for(int i = 0; i < len; ++i)
        {
            //for(int j = amount; j >= coins[i]; --j)
            for(int j = coins[i]; j <= amount; ++j)
            {
                //for(int k = 1; j-k*coins[i] >= 0; ++k)
                //if(dp[j-coins[i]*k] != -1)
                if(dp[j-coins[i]] != -1)
                {
                    if(dp[j] == -1 || dp[j-coins[i]] + 1 < dp[j])
                    {
                        dp[j] = dp[j-coins[i]] + 1;
                    }
                }
            }
        }
        
        return dp[amount];
    }
};
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        
        int** dp = new int*[n+1];
        for(int i = 0; i <= n; ++i)
        {
            dp[i] = new int[n+1];
        }
        
        //之前只初始化了00
        for(int i = 0; i <=n; ++i)
            dp[0][i] = 1;
        
        for(int i = 1; i <= n; ++i)
        {
            //枚举最后一个数字
            for(int j = 0; j <= i; ++j)
            {
                dp[i][j] = 0;
                if(S[i-1] == 'I')
                {
                    for(int k = j-1; k >= 0; --k)
                    {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= 1000000007;
                        //cout << S[i-1] << "|" << i << "|" << j << "|" << k << "|" << dp[i][j] << endl;
                    }
                }
                else
                {
                    for(int k = j+1; k <= i; ++k)
                    {
                        //后边加了个-1
                        dp[i][j] += dp[i-1][k-1];
                        dp[i][j] %= 1000000007;
                        //cout << S[i-1] << "|" << i << "|" << j << "|" << k << "|" << dp[i][j] << endl;
                    }
                }
            }
            //后边加的
            for(int j = i+1; j <= n; ++j)
            {
                dp[i][j] = dp[i][i];
            }
        }
        
        int sum = 0;
        for(int i = 0; i <= n; ++i)
        {
            sum += dp[n][i];
            sum %= 1000000007;
            //cout << dp[n][i] << endl;   
        }
        
        return sum;
    }
};

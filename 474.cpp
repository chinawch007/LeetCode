class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int** dp = new int*[m+1];
        for(int i = 0; i <= m; ++i)
        {
            dp[i] = new int[n+1];
        }
        
        for(int i = 0; i <= m; ++i)
            for(int j = 0; j <= n; ++j)
                dp[i][j] = 0;
        
        int sz = strs.size();
        int* count0 = new int[sz];
        int* count1 = new int[sz];
        
        for(int i = 0; i < sz; ++i)
        {
            count0[i] = 0;
            count1[i] = 0;
        }
        
        for(int i = 0; i < sz; ++i)
        {
            for(int j = 0; j < strs[i].size(); ++j)
            {
                if(strs[i][j] == '0')
                {
                    count0[i]++;
                }
                else
                {
                    count1[i]++;
                }
            }
        }
        
        for(int k = 0; k < strs.size(); ++k)
        {
            //此处注意要倒叙
            for(int i = m; i >= 0; --i)
                for(int j = n; j >= 0; --j)
                {
                    if(i-count0[k] >= 0 && j-count1[k] >= 0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i-count0[k]][j-count1[k]] + 1);
                    }
                }
        }
        
        return dp[m][n];
    }
};

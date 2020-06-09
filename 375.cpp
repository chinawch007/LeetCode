class Solution {
public:
    int getMoneyAmount(int n) {
        //为了dp[n+1][n]
        int** amount = new int*[n+2];
        for(int i = 0; i <= n+1; ++i)
            amount[i] = new int[n+2];
        
        for(int i = 1; i <= n+1; ++i)
        {
            amount[i][i] = 0;
            amount[i][i-1] = 0;
        }
            
        
        for(int l = 2; l <= n; ++l)
        {
            for(int i = 1; i <= n-l+1; ++i)
            {
                int mi = 2000000000;
                
                for(int j = i; j <= i+l-1; ++j)
                {
                    int tmp = j + max(amount[i][j-1], amount[j+1][i+l-1]);
                    if(tmp < mi)
                    {
                        mi = tmp;
                    }
                }
                
                amount[i][i+l-1] = mi;
            }
        }
        
        return amount[1][n];
    }
};

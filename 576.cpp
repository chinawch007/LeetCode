/*
    不是以对格子的迭代为主体,而是以步数的迭代为主体

*/

#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                dp[i][j][1] = 0;
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            dp[i][0][1] += 1;
            dp[i][n-1][1] += 1;
        }

        for(int j = 0; j < n; ++j)
        {
            dp[0][j][1] += 1;
            dp[m-1][j][1] += 1;
        }

        for(int k = 2; k <= N; ++k)
        {
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    dp[i][j][k] = 0;
                    if(i-1 >= 0)dp[i][j][k] = (int)(((long)dp[i][j][k] +(long) dp[i-1][j][k-1]) % 1000000007);
                    if(i+1 < m)dp[i][j][k] = (int)(((long)dp[i][j][k] + (long)dp[i+1][j][k-1]) % 1000000007);
                    if(j-1 >= 0)dp[i][j][k] = (int)(((long)dp[i][j][k] + (long)dp[i][j-1][k-1]) % 1000000007);
                    if(j+1 < n)dp[i][j][k] = (int)(((long)dp[i][j][k] + (long)dp[i][j+1][k-1]) % 1000000007);
                }
            }
        }

        long ret = 0;
        for(int k = 1; k <= N; ++k)
        {
            ret += dp[i][j][k];
            ret %= 1000000007;
        }    

        
        
        return (int)ret;
    }

    int dp[50][50][51];
};
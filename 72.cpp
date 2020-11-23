class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        int **dp = new int*[len1+1];
        for(int i = 0; i <= len1; ++i)
        {
            dp[i] = new int[len2+1];
            dp[i][0] = i;
        }

        for(int i = 0; i <= len2; ++i)
        {
            dp[0][i] = i;
        }
        dp[0][0] = 0;

        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = len1 + len2;
                    if(dp[i-1][j]+1 < dp[i][j])dp[i][j] = dp[i-1][j]+1;//删除
                    if(dp[i-1][j-1]+1 < dp[i][j])dp[i][j] = dp[i-1][j-1]+1;//替换
                    if(dp[i][j-1]+1 < dp[i][j])dp[i][j] = dp[i][j-1]+1;//插入

                    cout << i << "*" << j << "*";
                }

                cout << dp[i][j] << "|";
            }
            cout << endl;
        }

        return dp[len1][len2];
    }
};
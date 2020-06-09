/*
    起初按照常规想,建立个数组长度的dp,一个一个状态转移,但需要一个set去重
    看解答用26字符dp,并且细想,你以某个字符为结尾的最大长度即可表示所有以该字符为结尾的字符串

    出现了非常致命的错误,思维有混乱了
    你现在用的是last,但你之前用的是dp[i-1],即前一个字符的dp值,但你这次更新,未必会那么运气好遇上前一个字符的最长串,做了高估的更新
*/

#include<vector>
#include<string>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.size()==0)return 0;
        
        int dp[26];
        for(int i = 0; i < 26; ++i)dp[i] = 0;
        int sz = p.size();

        dp[p[0] - 'a'] = 1;

        int last = 1;
        for(int i = 1; i < sz; ++i)
        {
            if( (p[i] - p[i-1] + 26)  %  26 == 1)
            {
                if(last + 1 > dp[p[i] - 'a'])
                {
                    dp[p[i] - 'a'] = last + 1;
                }
                last++;

            }
            else
            {
                last = 1;
                if(dp[p[i] - 'a'] == 0)
                {
                     dp[p[i] - 'a'] = 1;
                }
                   
            }

        }

        int ret = 0;
        for(int i = 0; i < 26; ++i)
        {
            cout << dp[i] << endl;
            ret += dp[i];
        }
            

        return ret;
    }
};



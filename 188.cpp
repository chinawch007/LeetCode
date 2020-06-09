/*
    关于动态规划,不同的问题定义:
    我的想法是ijk,从i到j操作k次
    他是说前i个持有股票或是没持有股票操作k次
    我这边可以去除一个唯独,ij表示前i天操作j次,最后一天卖的话就向前枚举买的时间
*/
#include<vector>
#include<iostream>
#include<stdint.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();

        //此处原来语句位置是颠倒的
        if(k > (sz/2))k = sz/2;
        if(sz == 0 || k == 0)return 0;

        int mi[sz];
        int mii = INT32_MAX;
        for(int i = 0; i < sz; ++i)
        {
            if(prices[i] < mii)
            {
                mi[i] = mii = prices[i];
            }
            else
            {
                mi[i] = mi[i-1];
            }
        }

        //int dp[sz][k+1];

        int** dp = new int*[sz];
        for(int i = 0; i < sz; ++i)
        {
            dp[i] = new int[k+1];
            //for(int j = 0; j <= k; ++j)
                //dp[i][j] = 0;
        }

        //用mi来生成k=1时的情况
        dp[0][1] = INT32_MIN;
        for(int i = 1; i < sz; ++i)
        {
            dp[i][1] = max(dp[i-1][1], prices[i] - mi[i-1]);
        }

        //我计算的是保证出手j次的数组,原因是啥来着...
        //考虑操作次数大于天数的情况
        for(int j = 2; j <= k; ++j)
        {
            //此处原来赋0
            for(int i = 0; i < 2*j -1; ++i)
                dp[i][j] = INT32_MIN;

            for(int i = 2*j - 1; i < sz; ++i)
            {
                dp[i][j] = dp[i-1][j];
                for(int l = 2*j -2; l < i; ++l)
                {
                    //枚举在i处卖出的情况,一会还要跟i-1的位置比
                    //dp[i][j] = max(dp[i][j], max(dp[l-1][j], dp[l-1][j-1] + prices[i] - prices[l]) );
                    dp[i][j] = max(dp[i][j], dp[l-1][j-1] + prices[i] - prices[l]);
                }
                //dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }

        //此处ma应赋值为0
        //int ma = INT32_MIN;
        int ma = 0;
        for(int j = 1; j <= k; ++j)
        {
            if(dp[sz-1][j] > ma)
            {
                ma = dp[sz-1][j];
            }
        }
/*
        for(int j = 0; j <= k; ++j)
        {
            for(int i = 0; i < sz; ++i)
            {
                cout << dp[i][j] << "|";
            }
            cout << endl;
        }
*/
        return ma;
    }
};

int main()
{
    int k = 2;
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);

    Solution s;
    cout << s.maxProfit(k, v) << endl;

    return 0;
}
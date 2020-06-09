#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)return 0;
        vector<int> vMax;
        vMax.resize(prices.size());
        for(int i = 0; i < vMax.size(); ++i)vMax[i] = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(prices[j] < prices[i])
                {
                    if( (j-1>=0 ? vMax[j-1] : 0) + prices[i] - prices[j] > vMax[i])
                    {
                        vMax[i] = (j-1>=0 ? vMax[j-1] : 0) + prices[i] - prices[j];
                        //此步骤忘了,注意编程前计划构思的完善性
                        //if(vMax[i-1] > vMax[i])vMax[i] = vMax[i -1];
                    }

                }
            }
            //错误,之前在上边
            if(vMax[i-1] > vMax[i])vMax[i] = vMax[i -1];
        }
        for(int i = 0; i < vMax.size(); ++i)cout << vMax[i] << "|";
        cout << endl;

        return vMax[prices.size() - 1];
    };
};

int main()
{
    Solution s;

    int n, t;
    vector<int> vi;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> t;
        vi.push_back(t);
    }

    cout << s.maxProfit(vi) << endl;

    return 0;
}
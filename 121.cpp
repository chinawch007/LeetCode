#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)return 0;
        
        int min = prices[0], re = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] > min && prices[i] - min > re)re = prices[i] - min;
            if(prices[i] < min)min = prices[i];
        }  

        return re;
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
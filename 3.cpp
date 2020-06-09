#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ma = -1, l = 0;
        map<char, int> mc;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mc.find(s[i]) == mc.end())
            {
                mc[s[i]] = i;
                ++l;
            }
            else
            {
                //更新记录
                if(l > ma)
                {
                    ma = l;
                }

                //语句顺序2
                //l = i - mc[s[i]];
                int len = i - mc[s[i]];

                //截短
                //1编程习惯...
                //cout << i - l << "|" << mc[s[i]] << endl;

                for(int j = i - l; j <= mc[s[i]]; ++j)
                {
                    //cout << "erase:" << s[i] << endl;
                    mc.erase(s[j]);
                }

                //语句顺序1
                //l = i - mc[s[i]];
                l = len;

                mc[s[i]] = i;
            }
        }

        if(l > ma)ma = l;

        return ma;
    };
};

int main()
{
    Solution s;
    string in;
    cin >> in;
    cout << s.lengthOfLongestSubstring(in) << endl;
    
    return 0; 
}
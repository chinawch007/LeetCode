//最开始以为是个线性递增的动态规划，以i结尾最长可以从以i-1为结尾最长得出，想当然尔
class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")return "";

        int l = s.size();
        for(int i=0; i<l; i++)
        {
            for(int j =0; j < l; ++j)
                b[i][j] = false;
            b[i][i] = true;
        }
        
        for(int i = 0; i < l; ++i)
        {
            mPos[s[i]].push_back(i);
        }

        for(int i = 0; i < l; ++i)
        {
            vector<int>& v = mPos[s[i]];

            auto iter = lower_bound(v.begin(), v.end(), i);

            for(;iter >= v.begin(); --iter)
            {
                int start = *iter;
                if(i-start > 1)
                {
                    if(b[start+1][i-1])
                    {
                        b[start][i] = true;
                        if(i-start+1 > maxL)
                        {
                            maxL = i-start+1;
                            maxS = s.substr(start, i-start+1);
                        }
                    }
                }
                else
                {
                    b[start][i] = true;
                    if(i-start+1 > maxL)
                    {
                        maxL = i-start+1;
                        maxS = s.substr(start, i-start+1);
                    }
                }
            }
        }

        return maxS;
    }

    map<char, vector<int> > mPos;
    bool b[1000][1000];
    int maxL;
    string maxS;
};
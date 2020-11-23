class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        cout << len << endl;
        bool *b = new bool[len+1];
        b[0] = true;
        for(int i = 1; i <= len; ++i)
            b[i] = false;//不初始化会RT

        set<string> ss;
        for(int i = 0; i < wordDict.size(); ++i)
        {
            ss.insert(wordDict[i]);
        }

        for(int i = 1; i <= len; ++i)
        {
            for(int j = i; j >= 1; --j)
            {
                string tmp = s.substr(j-1, i-j+1);
                cout << j << endl;
                if(ss.find(tmp) != ss.end() && b[j-1])
                {
                    b[i] = true;
                    break;
                }
            }
        }

        return *(b + len);
        //return b[5];
        //return b[0];
    }
};
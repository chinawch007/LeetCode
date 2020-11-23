class Solution {
public:
//思路：确定一部分，再确定另一部分，两部分合起来就是搜索
    bool handle(int l, string S)
    {
        set<string> ss;

        for(int i = 0; i <= S.size()-1-l+1; ++i)
        {
            string s = S.substr(i, l);

            if(ss.find(s) != ss.end())
            {
                return true;
            }

            ss.insert(s);
        }

        return false;
    };

    int longestRepeatingSubstring(string S) {
        int s = 1, e = S.size()-1;
        int l;
        int max = 0;
        while(e > s+1)
        {
            l = (s+e)/2;
            bool ret = handle(l, S);
            if(ret && l>max)max = l;
            if(ret)
            {
                s = l;
            }
            else
            {
                e = l;
            }
        }
        if(handle(s, S) && s > max)max = s;
        if(handle(e, S) && e > max)max = e;

        return max;
    }
};
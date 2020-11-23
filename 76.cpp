class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";

        map<char, int> mReq;
        map<char, int> mCount;
        int iNeed = 0;
        for(int i = 0; i < t.size(); ++i)
        {
            mReq[t[i]]++;
            iNeed++;
        }

        int mHave = 0;
        /*
        for(int i = 0; i < t.size(); ++i)
        {
            mCount[s[i]]++;
            if(mReq.find(s[i]) != mReq.end() && mCount[s[i]] <= mReq[s[i]])
            {
                mHave++;
            }
        }
        if(mHave == iNeed)return s.substr(t.size());
        */

        int iStart = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mReq.find(s[i]) != mReq.end())
            {
                iStart = i;
                break;
            }
        }
        if(iStart == s.size())return "";

        int start = iStart;
        string minS("");
        int minl = s.size()+1;
        for(int i = iStart; i < s.size(); ++i)
        {
            mCount[s[i]]++;
            if(mReq.find(s[i]) != mReq.end() && mCount[s[i]] <= mReq[s[i]])
            {
                mHave++;
            }

            //此处要移动start直到不满足要求
            while(mHave == iNeed)
            {
                if(i-start+1 < minl)
                {
                    minl = i-start+1;
                    minS = s.substr(start, i-start+1);
                }

                mCount[s[start]]--;
                if(mCount[s[start]] < mReq[s[start]])
                {
                    mHave--;
                }
                start++;
                if(start >= s.size())break;
                while(start < s.size() && mReq.find(s[start]) == mReq.end()){start++;}
            }

        }
        
        return minS;
    }
};
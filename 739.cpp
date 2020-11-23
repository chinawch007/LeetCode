class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> ret(len);
        stack<int> si;

        si.push(len-1);
        ret[len-1]=0;
        for(int i = len-2; i >= 0; --i)
        {
        while(si.size() > 0 && T[si.top()] <= T[i])si.pop();
            if(si.size() == 0)ret[i] = 0;
            else ret[i] = si.top()-i;
            si.push(i);
        }

        return ret;
    }
};
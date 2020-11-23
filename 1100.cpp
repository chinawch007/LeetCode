class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        cnt = 0;
        cntMore = 0;
        int len = S.size();

        for(int i = 0; i <= len-1; ++i)
        {
            m[S[i]]++;
            if(m[S[i]] == 2)
            {
                cntMore++;
            }

            if(i == K-1 && cntMore == 0)cnt++;

            if(i >= K)
            {
                m[S[i-K]]--;

                if(m[S[i-K]] == 1)
                {
                    cntMore--;
                }

                if(cntMore == 0)cnt++;
            }
        }

        return cnt;
    }

    int cntMore;
    int cnt;
    map<char, int> m;
    queue<char> q;
};
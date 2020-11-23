class Solution {
public:
    int minSwaps(vector<int>& data) {
        if(data.size() == 0)return 0;

        int len = data.size();
        s[0] = 0;
        for(int i = 1;i <= len; ++i)
        {
            s[i] = s[i-1] + data[i-1];
        }

        int min = s[len];
        int l = s[len];

        for(int i = 1; i <= len-l+1; ++i)
        {
            if( l - (s[i+l-1] - s[i-1]) < min)min = l - (s[i+l-1] - s[i-1]);
        }

        return min;
    }

    int s[100001];
};
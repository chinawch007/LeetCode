class Solution {
public:
    int maxA(int N) {
        max[0] = 0;
        max[1] = 1;
        max[2] = 2;
        max[3] = 3;

        for(int i = 4; i <= 50; ++i)
        {
            max[i] = i;
            for(int j = 1; j <= i-2; ++j)
            {
                int tmp = max[j] + max[j] * (i-2-j);
                if(tmp > max[i])max[i] = tmp;
            }
        }

        return max[N];
    }

    int dp[51][51];//长度i，
    int max[51];
};
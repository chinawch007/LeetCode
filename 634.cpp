class Solution {
public:
    int findDerangement(int n) {
        a[1] = 0;
        a[2] = 1;
        a[3] = 2;
        for(int i = 4; i <= n; ++i)
        {
            a[i] = ( (i-1) * ( (a[i-1] + a[i-2]) % 1000000007 ) ) % 1000000007;
        }

        return (int)a[n];
    }

    long a[1000001];
};
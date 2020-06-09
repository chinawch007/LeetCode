#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)return 0;

        int n = matrix.size();
        int o = matrix[0].size();

        vector< vector<int> > e;
        e.resize(n);
        for(int i = 0; i < n; ++i)
        {
            e[i].resize(o);
        }

        int ma = 0;
        for(int i = 0; i < o; ++i)
        {
            e[0][i] = matrix[0][i] - '0';
            if(e[0][i] == 1)ma = 1;
        }

        for(int i = 0; i < n; ++i)
        {
            e[i][0] = matrix[i][0] - '0';
            if(e[i][0] == 1)ma = 1;
        }

        int l = 0, k = 0, m = 0;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j < o; ++j)
            {
                if(matrix[i][j] != '1')continue;

                l = e[i-1][j-1];

                for(k = i - 1; k > i - 1 - l; --k)
                {
                    if(matrix[k][j] != '1')break;
                }

                for(m = j - 1; m > j - 1 - l; --m)
                {
                    if(matrix[i][m] != '1')break;
                }

                e[i][j] = i - k < j - m ? i - k : j - m;
                if(e[i][j] > ma)ma = e[i][j];
            }
        }

        return ma * ma;
    }
};

int main()
{
    Solution s;
/*
    int n, t;
    vector<int> vi;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> t;
        vi.push_back(t);
    }

    cout << s.maxProfit(vi) << endl;
*/
    return 0;
}
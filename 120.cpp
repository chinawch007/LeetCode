#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();

        vector<int> v[2];
        v[0].resize(n);
        v[1].resize(n);

        v[0][0] = triangle[0][0];

        for(int i = 1; i < n; ++i)
        {
            vector<int>& vFrom = v[1 - (i % 2)];
            vector<int>& vTo = v[i % 2];

            vTo[0] = vFrom[0] + triangle[i][0];
            cout << vTo[0] << "|";

            for(int j = 1; j < i; ++j)
            {
                vTo[j] =  triangle[i][j] + (vFrom[j] < vFrom[j-1] ? vFrom[j] : vFrom[j-1]);
                cout << vTo[j] << "|";
            }

            //vTo[i] = vFrom[i - 1] + triangle[i][i - 1];
            vTo[i] = vFrom[i - 1] + triangle[i][i];
            cout << vTo[i] << endl;
        }

        int min = 2100000000;
        vector<int>& vRet = ((n - 1) % 2 == 0 ? v[0] : v[1]);
        for(int i = 0; i < n; ++i)
        {
            cout << vRet[i] << "|";
            if(vRet[i] < min)min = vRet[i];
        }

        return min;
    };
};

int main()
{
    Solution s;

    vector< vector<int> > v;

    int n, t;
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; ++j)
        {
            cin >> t;
            v[i].push_back(t);
        }
    }

    cout << s.minimumTotal(v) << endl;

    return 0;
}
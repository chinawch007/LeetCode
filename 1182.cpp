class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        for(int i = 0; i < colors.size(); ++i)
        {
            m[colors[i]].push_back(i);
        }

        vector<int> ret;

        for(int i = 0; i < queries.size(); ++i)
        {
            int j = queries[i][0];
            int c = queries[i][1];

            if(m[c].size() == 0)
            {
                ret.push_back(-1);
                continue;
            }

            auto w = lower_bound(m[c].begin(), m[c].end(), j);

            if(w == m[c].begin())
            {
                ret.push_back(*w - j);
            }
            else if(w == m[c].end())
            {
                ret.push_back(j - m[c][m[c].size()-1]);
            }
            else
            {
                ret.push_back( j-*(w-1) < *w-j ? j-*(w-1) : *w-j ) ;
            }
        }

        return ret;
    }

    map<int, vector<int> > m;
};
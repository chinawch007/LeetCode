struct node
    {
        int s;
        int e;
    };

    bool cmp(node x, node y)
    {
        return x.s < y.s || (x.s == y.s && x.e < y.e);
    };

    struct cmp2{
        bool operator()(int x, int y)
        {
            return x > y;
         };
    };
    

class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)return 0;
        vector<node> v;
        for(int i = 0; i < intervals.size(); ++i)
        {
            node n;
            n.s = intervals[i][0];
            n.e = intervals[i][1];

            v.push_back(n);
        }
        sort(v.begin(), v.end(), cmp);

        priority_queue<int, vector<int>, cmp2> q;
        q.push(v[0].e);

        for(int i = 1; i < v.size(); ++i)
        {
            int e = q.top();
            cout << e << endl;
            if(e <= v[i].s)
            {
                q.pop();
                q.push(v[i].e);
            }
            else
            {
                q.push(v[i].e);
            }
        }

        return q.size();
    }
};
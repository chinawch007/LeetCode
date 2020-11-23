class Solution {
public:
    struct node
    {
        int ts;
        int a;
        int b;
        node (int ts, int a, int b): a(a), b(b), ts(ts){};
        bool operator< (node o){return ts < o.ts;};
    };

    bool un(int i, int j)
    {
        while(u[i] != i)
        {
            u[i] = u[u[i]];
            i = u[i];
        }

        while(u[j] != j)
        {
            u[j] = u[u[j]];
            j = u[j];
        }

        //此次没有添加新的连结
        if(i == j)return false;

        u[i] = j;
        return true;
    }

    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<node> v;
        for(int i = 0; i < N; ++i)u[i] = i;

        for(int i = 0; i < logs.size(); ++i)
        {
            node n(logs[i][0], logs[i][1], logs[i][2]);
            v.push_back(n);
        }

        sort(v.begin(), v.end());

        int cnt = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            if(un(v[i].a, v[i].b))cnt++;
            if(cnt == N-1)return v[i].ts;
        }

        return -1;
    }

    int u[100];
};
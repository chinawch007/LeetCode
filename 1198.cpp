class Solution {
public:
    struct node
    {
        int v;
        int s;
        int cur;
    };

    //成员函数不能是私有的
    struct cmp
    {
        bool operator() (struct node n1, struct node n2)
        {
            return n1.v > n2.v ;
        };
    };

    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cur[500];
        int cnt[10001];
        for(int i = 0; i <= 10000; ++i)
            cnt[i] = 0;

        for(int i = 0; i < m; ++i)
        {
            node n;
            n.v = mat[i][0];
            n.cur = 0;
            n.s = i;

            q.push(n);
            if(++cnt[n.v] == m)return n.v;
        }

        //有一个数组耗光了就说明查找失败了
        while(1)
        {
            node t = q.top();
            q.pop();
            cnt[t.v]--;

            if(t.cur == n-1)return -1;

            node p;
            p.v = mat[t.s][t.cur+1];
            p.cur = t.cur+1;
            p.s = t.s;
            
            q.push(p);
            if(++cnt[p.v] == m)return p.v;
        }

        return -1;
    }

    priority_queue<node, vector<node>, cmp> q;
};
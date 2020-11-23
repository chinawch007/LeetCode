class Solution {
public:
    struct edge
    {
        int a;
        int b;
        int l;
        edge(int a, int b, int l):a(a), b(b), l(l){};
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

    struct cmp{
        bool operator()(edge x, edge y){return x.l > y.l;}
    };

    int minimumCost(int N, vector<vector<int>>& connections) {
        for(int i = 0; i <= 10000; ++i)
        {
            u[i] = i;
        }

        for(int i = 0; i < connections.size(); ++i)
        {
            q.push(edge(connections[i][0], connections[i][1], connections[i][2]));
        }

        int sum = 0;
        int cnt = 0;
        while(!q.empty())
        {
            edge e = q.top();
            q.pop();
            
            if(un(e.a, e.b))
            {
                sum += e.l;
                ++cnt;
            }
        }

        if(cnt == N-1)
            return sum;
        else
            return -1;

    }

    int u[10001];
    priority_queue<edge, vector<edge>, cmp> q;
};
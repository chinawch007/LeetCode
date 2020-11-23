class Leaderboard {
public:
    struct node
    {
        int p;
        int s;
        int v;
        node(int p, int s, int v) : p(p), s(s), v(v){};
    };

    struct cmp{
        bool operator()(node x, node y){return x.s < y.s;}
    };

    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
        ms[playerId] += score;
        node n(playerId, ms[playerId], ++mv[playerId]);
        q.push(n);
    }
    
    //靠，你用堆把来算topk
    //---结果空栈top，core了
    int top(int K) {
        int i = 0;
        int sum = 0;
        vector<node> v;
        while(1)
        {
            node n = q.top();
            q.pop();
            if(n.v != mv[n.p])continue;
            sum += n.s;
            v.push_back(n);
            if(++i == K)break;
        }

        for(int i = 0; i < v.size(); ++i)
        {
            q.push(v[i]);
        }

        return sum;
    }
    
    void reset(int playerId) {
        node n(playerId, 0, ++mv[playerId]);
        ms[playerId] = 0;
        q.push(n);
    }

    priority_queue<node, vector<node>, cmp> q;
    map<int, int> mv;
    map<int, int> ms;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
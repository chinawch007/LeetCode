map<int, int> t;

class Solution {
public:
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return t[a] >= t[b];
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        t.clear();

        for(int i = 0; i < len; ++i)
        {
            t[nums[i]]++;
        }

        priority_queue<int, vector<int>, cmp> p;

        auto it = t.begin();
        for(; it != t.end(); ++it)
        {
            cout << it->first << endl;
            p.push(it->first);
            if(p.size() > k)p.pop();
        }

        vector<int> ret;
        while(p.size() > 0)
        {
            ret.push_back(p.top());
            p.pop();
        }

        return ret;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        int* d = new int[n];
        for(int i = 0; i < n; ++i)
            d[i] = 0;
        
        vector< vector<int> > e(n);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            e[prerequisites[i][1]].push_back(prerequisites[i][0]);
            d[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i)
        {
            if(d[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> ret;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            
            ret.push_back(t);
            //别重复推了
            //d[t] = -1;
            
            for(int j = 0; j < e[t].size(); ++j)
            {
                if(--d[e[t][j]] == 0)
                {
                    q.push(e[t][j]);
                }
                
            }
        }
        if(ret.size() != n)ret.clear();
        
        return ret;
    }
};

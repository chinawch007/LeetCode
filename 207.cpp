class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        map<int, vector<int> > g;
        int* in = new int[numCourses];
        for(int i = 0; i < numCourses; ++i)in[i] = 0;

        for(int i = 0; i < prerequisites.size(); ++i)
        {
            int e = prerequisites[i][0];
            int s = prerequisites[i][1];

            g[s].push_back(e);
            in[e]++;
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(in[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int s = q.front();
            q.pop();

            for(int i = 0; i < g[s].size(); ++i)
            {
                in[g[s][i]]--;
                if(in[g[s][i]] == 0)q.push(g[s][i]);
            }
        }

        bool flag = true;
        for(int i = 0; i < numCourses; ++i)
        {
            if(in[i] > 0)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
};
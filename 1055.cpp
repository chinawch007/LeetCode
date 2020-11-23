class Solution {
public:
    //返回此次巡查到成功找到的结尾
    void dfs(int cnt, int i, int j)//第cnt次从source中找字符去从target中匹配
    {
        if(j == ta.size())
        {
            if(i==0)cnt--;//没开始选取字母呢
            if(cnt < mi)
            {
                mi = cnt;
            }
            return;
        }

        vector<int>& v = m[ta[j]];
        auto iter = lower_bound(v.begin(), v.end(), i);
        if(iter != v.end())
        {
            int tmp = *iter+1;
            if(tmp == so.size())
            {
                dfs(cnt+1, 0, j+1);
            }
            else
            {
                dfs(cnt, tmp, j+1);
            }
            
        }
        else
        {
            dfs(cnt+1, 0, j);
        }

        //此处注意，不能循环整个数组遍历，此处选取字母类似于贪心，能选择尽量选择

    };

    int shortestWay(string source, string target) {
        so = source;
        ta = target;

        for(int i = 0; i < so.size(); ++i)
        {
            m[so[i]].push_back(i);
        }
        mi = ta.size() + 1;

        for(int i = 0; i < ta.size(); ++i)
        {
            if(m.find(ta[i]) == m.end())
            {
                return -1;
            }
        }

        dfs(1, 0, 0);
            
        return mi == ta.size() ? -1 : mi;
    }

    string so;
    string ta;
    map<char, vector<int> > m;
    int mi;
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string> > link;
        map<string, vector<string> > g;
        map<string, int> step;
        queue<string> q;

        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); ++i)
        {
            for(int j = 0; j < wordList[i].size(); ++j)
            {
                string tmp = wordList[i];
                tmp[j] = '*';
                link[tmp].push_back(wordList[i]);
            }
        }

        for(auto iter = link.begin(); iter != link.end(); ++iter)
        {
            cout << iter->first << endl;
            vector<string>& v = iter->second;
            for(int i = 0; i < v.size(); ++i)
            {
                for(int j = 0; j < v.size(); ++j)
                {
                    if(j == i)continue;
                    g[v[i]].push_back(v[j]);
                    cout << v[i] << "|" << v[j] << endl;
                }
            }
        }

        step[beginWord] = 0;
        q.push(beginWord);

        while(!q.empty())
        {
            string s = q.front();
            q.pop();

            cout << s << endl;

            vector<string>& v = g[s];
            for(int i = 0; i < v.size(); ++i)
            {
                if(v[i] == endWord)
                {
                    return step[s] + 1 + 1;
                }

                if(step.find(v[i]) == step.end() )
                {
                    step[v[i]] = step[s] + 1;
                    q.push(v[i]);
                }
            }
        }

        return 0;
    }
};
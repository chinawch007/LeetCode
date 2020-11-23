class Solution {
public:
    void dfs(int i, int& sum, vector<int>& candidates, vector<int>& now, vector< vector<int> >& ret)
    {
        if(sum == target)
        {
            cout << sum << "|" << target << endl;
            ret.push_back(now);
            return;
        }

        for(int j = i; j < candidates.size() && sum + candidates[j] <= target; ++j)
        {
            now.push_back(candidates[j]);
            sum += candidates[j];
            dfs(j, sum, candidates, now, ret);
            sum -= candidates[j];
            now.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector< vector<int> > ret;
        vector<int> now;
        this->target = target;
        int sum = 0;

        dfs(0, sum, candidates, now, ret);

        return ret;
    }

    int target;
};
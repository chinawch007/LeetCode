class Solution {
public:
    bool cmp(int a, int b){return a < b; }

    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int> > q;
        
        for(int i = 0;i < sticks.size(); ++i)
        {
            q.push(sticks[i]);
        }

        int sum = 0;

        while(q.size() > 1)
        {
            int i1 = q.top();
            q.pop();
            int i2 = q.top();
            q.pop();

            cout << i1 << "|" << i2 << endl;

            sum += (i1 + i2);
            q.push(i1+i2);

        }

        return sum;
    }
};
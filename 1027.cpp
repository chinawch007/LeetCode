class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n==0 || n==1 || n==2)return n;
        
        //sort(A.begin(), A.end());
        
        int ma = 0;
        for(int i = 0; i < n; ++i)
            if(A[i] > ma)ma = A[i];
        
        vector< vector<int> > b(ma+1);
        //b.resize(ma+1);
        
        for(int i = 0; i < n; ++i)
            b[A[i]].push_back(i);
        
        //反着推吧，i比j大
        int** dp = new int*[n];
        for(int i = 0; i < n; ++i)
        {
            dp[i] = new int[n];
        }
        
        int best = 2;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i-1; j < i && j >= 0; --j)
            {   
                dp[i][j] = 2;
                
                int c = A[i] - A[j];
                int t = A[j] - c;
                //传入的数组数值不能是负数啊
                //开始时没后边你的条件
                if(t < 0 || t > ma)continue;
                
                for(int l = 0; l < b[t].size(); ++l)
                {
                    if(b[t][l] > j)continue;
                    if(dp[j][b[t][l]] + 1 > dp[i][j])
                        dp[i][j] = dp[j][b[t][l]] + 1;
                }            
                
                if(dp[i][j] > best)best = dp[i][j];
                
                //cout << i << "|" << j  << "|" << dp[i][j] << endl;
            }
        }
        
        return best;
    }
};

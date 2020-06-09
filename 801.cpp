class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        int** dp = new int*[2];
        dp[0] = new int[n];
        dp[1] = new int[n];
        
        dp[0][0] = 0;
        dp[1][0] = (A[0] == B[0] ?  0 : 1);//这地方挺有意思
        for(int i = 1; i < n; ++i)
        {
            if(A[i] > A[i-1] && B[i] > B[i-1])
            {
                if(A[i] > B[i-1] && B[i] > A[i-1])
                {
                    if(A[i] == B[i])
                    {
                        dp[1][i] = dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
                    }
                    else
                    {
                        dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
                        dp[1][i] = min(dp[0][i-1], dp[1][i-1]) + 1;
                    }
                }
                else
                {
                    dp[0][i] = dp[0][i-1];
                    dp[1][i] = dp[1][i-1] + 1;
                }
                
                //少考虑一种情况，交换后A的不一定大于B的
                
                cout << "case 1," << i << ":" << dp[0][i] << "|" << dp[1][i] << endl;   
            }
            else if(A[i] <= A[i-1] || B[i] <= B[i-1])
            {
                dp[0][i] = dp[1][i-1];
                dp[1][i] = dp[0][i-1] + (A[i] == B[i] ?  0 : 1);
                cout << "case 1," << i << ":" << dp[0][i] << "|" << dp[1][i] << endl; 
            } 
        }
        
        return min(dp[0][n-1], dp[1][n-1]);
    }
};

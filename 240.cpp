class Solution {
public:
    bool dp(vector<vector<int>>& matrix, int target, int si, int sj, int ei, int ej)
    {
        int mid = (sj + ej) / 2;
        
        //对mid做特殊检查
        
        int i;
        for(i = si; i <= ei; ++i)
        {
            if(matrix[i][mid] > target)
            {
                break;
            }
            else if(matrix[i][mid] == target)
            {
                return true;
            }
        }
        
        bool b1 = false, b2 = false;
        
        if(i <=  ei && mid-1 >= sj)
            b1 = dp(matrix, target, i, sj, ei, mid-1);
        if(mid+1 <= ej && i-1 >= si)
            b2 = dp(matrix, target, si, mid+1, i-1, ej);
        
        return b1 || b2;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)return false;
        if(matrix[0].size() == 0)return false;
        
        int m = matrix.size(), n = matrix[0].size();
        return dp(matrix, target, 0, 0, m-1, n-1);
    }
};

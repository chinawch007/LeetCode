//把所有外部的节点搞成一个，这是个小创新
class Solution {
public:
    int* a;
    
    void un(int i, int j)
    {
        //a[j] = fin(i);
        a[fin(j)] = fin(i);
    }
    
    int fin(int i)
    {
        while(a[i] != i)
        {
            a[i] = a[a[i]];
            i = a[i];
        }
        
        return i;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)return;
        int n = board[0].size();
        if(n == 0)return;
        //cout << m << "|" << n << endl;
        
        a = new int[m*n+1];
        //a[0] = 0;
        //要全部初始化才行
        for(int i = 0; i <= m*n; ++i)
            a[i] = i;
        
        //刚开始想跑两遍矩阵处理完，现在看能不能跑一遍处理完
        //搞不好最后一个点才通到外边，没法一遍确认
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    //cout << i << "|" << j << endl;
                    
                    if(i == 0 || i == m-1 || j == 0 || j == n-1)
                    {
                        //算对应坐标，要两个轴都+1才行---都搞错了
                        un(0, i*n + (j+1));
                        //cout << "un:" << 0 << "," << i*m + (j+1) << "|";
                    }
                    
                    //少写后边的条件了
                    if(i > 0 && board[i-1][j] == 'O')
                    {
                        un((i-1)*n + (j+1), i*n + (j+1));
                        //cout << "un:" << (i-1)*m + (j+1) << "," << i*m + (j+1) << "|";
                    }
                    
                    if(j > 0 && board[i][j-1] == 'O')
                    {
                        un(i*n + j, i*n + j+1);
                        //cout << "un:" << i*m + j << "," << i*m + (j+1) << "|";
                    }
                    
                    //cout << endl;
                }
            }
        }
        
        cout << a[0] << endl;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cout << a[i*n + (j+1)] << "|";
            }
            cout << endl;
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    if( fin(0) != fin(i*n + (j+1)) ) 
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};

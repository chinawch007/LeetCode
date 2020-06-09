class Solution {
public:
    //传进来的都要是1~n的数字模式
    void part(vector<int>& v, int start, int end)
    {
        int len = end - start + 1, mid;
        
        if(len == 1)
        {
            v[start] = 1;
            return;
        }
        
        if(len % 2 == 0)
        {
            mid = start + len/2 - 1;
            
        }
        else
        {
            mid = start + len/2;
        }
        
        part(v, start, mid);
        for(int i = start; i <= mid; ++i)
        {
            v[i] = 2*v[i] - 1;
        }
        
        part(v, mid+1, end);
        for(int i = mid+1; i <= end; ++i)
        {
            v[i] = 2*v[i];
        }
        
        
        
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> v;
        v.resize(N);
        
        part(v, 0, N-1);
        
        return v;
    }
};

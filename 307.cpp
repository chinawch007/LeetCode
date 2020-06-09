class NumArray {
public:
    int* a;
    int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        a = new int[2*n];
        
        for(int i = n; i < 2*n; ++i)
        {
            a[i] = nums[i-n];
        }
        
        for(int i = n-1; i >= 1; --i)
        {
            a[i] = a[2*i] + a[2*i+1];
        }
    }
    
    void update(int i, int val) {
        int p = n + i;
        int c = val - a[p];
        a[p] = val;
        
        p /= 2;
        
        while(p >= 1)
        {
            a[p] += c;
            p /= 2;
        }
        
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        i += n;
        j += n;
        
        while(i <= j)
        {
            if(i % 2 == 1)
            {
                sum += a[i];
                ++i;
            }
               
            if(j % 2 == 0)
            {
                sum += a[j];
                --j;
            }
            
            i /= 2;
            j /= 2;
        }
               
        return sum;
    }
};

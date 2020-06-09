class Solution {
public:
    //添加第4个参数的必要性
    bool dfs(vector<int>& nums, int* b, int t, int s)
    {
        //cout << "want:" << t << "|step:" << s << "|" ;
        
        //忘写这个了，递归的尽头
        //少写了后边的条件
        //到k步就可以了，剩下的可以凑一组
        if(s == k && t == this->t)return true;
        //if(s == k)return true;
        
        int n = nums.size();
        int i = n-1;
        for(; i >= 0; --i)
        {
            //cout << i << "|" << nums[i] << "|" << t << "|" << endl;
            if(b[i] == 0 && nums[i] <= t)
            {
                b[i] = s;
                
                //cout << "choose" << nums[i] << endl;
                
                //用一个变量名字搞混了。。。
                //if(dfs(nums, b, t-nums[i]==0 ? t : t-nums[i], t-nums[i]==0 ? s+1 : s))
                if(dfs(nums, b, t-nums[i]==0 ? this->t : t-nums[i], t-nums[i]==0 ? s+1 : s))
                {
                    return true;
                }
                
                b[i] = 0;
            }
        }
        
        //意味在这个s轮次凑t失败，
        return false;
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        this->k = k;
        
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
        }
        
        if(sum % k != 0)return false;
        
        int t = sum / k;
        this->t = t;
        
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] > t)return false;
        }
        
        int* b = new int[n];
        for(int i = 0; i < n; ++i)
            b[i] = 0;
        
        return dfs(nums, b, t, 1);
    }
    
    int k,t;
};

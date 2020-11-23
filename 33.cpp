class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int s = 0, e = len-1;
        int b = nums[0];
        int t = -1;
        while(e>s)
        {
            int m = (s+e)/2;
            if(nums[m]>=b && nums[m+1]<b)
            {
                t = m;
                break;
            }

            if(nums[m] >= b && nums[m+1]>b)
            {
                s = m+1;
            }
            else 
            {
                e = m-1;
            }
        }
        if(t == -1)t = s;
        cout << t << endl;

        if(target >= b)
        {
            s = 0;
            e = t;
        }
        else
        {
            s = t+1;
            e = len-1;
        }
        
        while(e>s)
        {
            int m = (e+s)/2;
            if(nums[m] == target)
            {
                return m;
            }
            else if(nums[m] > target)
            {
                e = m-1;
            }
            else
            {
                s = m+1;
            }
        }
        if(nums[e] == target)return e;
        else return -1;
    }
};
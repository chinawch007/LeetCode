class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();

        if(len == 0 || len == 1)return 0;

        int s = 0, e = len-1;
        int ma = 0;
        while(s < e)
        {
            if( min(height[s], height[e]) * (e-s) > ma )ma = min(height[s], height[e]) * (e-s);
            height[s] <= height[e] ? ++s : --e;
        }

        return ma;
    }
};
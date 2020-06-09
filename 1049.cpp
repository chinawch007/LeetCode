//关键是说我没法把最小重量定义为状态，因为这个没法转化
//所以说还是没有理解问题的性质，一个是多项式加减，一个是分成两坨差最小
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<60001> b;
        b.reset();
        b[30000] = 1;
        
        int sz = stones.size();
        for(int i = 0; i < sz; ++i)
        {
            b = ( (b << stones[i]) | (b>> stones[i]) );
        }
        
        int i = 0;
        for(; i < 30000; ++i)
        {
            if(b[30000+i])break;
        }
        int j = 0;
        for(; j < 30000; ++j)
        {
            if(b[30000+j])break;
        }
        
        return min(i,j);
    }
};

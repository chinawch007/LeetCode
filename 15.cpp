#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > vRet;
        for(int i = 0; i < nums.size(); ++i)
            for(int j = i + 1; j < nums.size(); ++j)
                for(int k = j + 1; k < nums.size(); ++k)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> vTmp;
                        vTmp.push_back(nums[i]);
                        vTmp.push_back(nums[j]);
                        vTmp.push_back(nums[k]);
                        vRet.push_back(vTmp);
                    }
                }
    }
};

int main()
{


    return 0;
}
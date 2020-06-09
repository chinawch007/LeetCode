#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); ++i)
        {
            nums[0] ^= nums[i];
        }
        

        cout << nums[0];
    }
};

int main()
{
    Solution s;
    vector<int> vIn;
    int n ;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vIn.push_back(t);
    }

    s.singleNumber(vIn);
    
    return 0; 
}
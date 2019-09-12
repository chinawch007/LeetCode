/*
    期初想用map确定新插入的元素的位置,但实际上不行,因为有重复元素
    直接一个归并排序就秒了
*/

#include<vector>
#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        
        vector<int> ret(sz, 0);
        vector<int> merge[2];
        merge[0].resize(sz);
        merge[1].resize(sz);

        for(int i = 0; i < sz; ++i)
        {
            merge[0][i] = i;
        }

        int f = 0;
        for(int i = 1; i < sz; i*=2)
        {
            
            for(int j = 0; j < sz; j+=2*i)
            {
                int k = j;
                int l = j+i;
                //cout << "k:" << k << ",l:" << l << endl;
                //此处原来少个=
                //这地方是个bug啊,这部分流程核心点是两个数组之间的互导,你退了这部分就不导了
                //if(l >= sz)break;

                int t = (f+1)%2;
                //原来写成sz-1了,边界条件
                int kend = l, lend = min(l+i, sz);
                //cout << "kend:" << kend << ",lend:" << lend << endl;

                //m之前赋值成i了
                int sum = 0, m = j;
                while( (k < kend || l < lend) && (m < sz))
                {
                    //处理有一个队列为空的情况
                    //cout << merge[f][k] << "|" << nums[merge[f][k]] << "|" << merge[f][l] << "|" << nums[merge[f][l]] << endl;

                    //不break之后,把后变的l条件从=变成>=了
                    //if( m < sz && ( ( k < kend && l < lend && nums[merge[f][k]] <= nums[merge[f][l]] ) || l >= lend) )
                    if( ( k < kend && l < lend && nums[merge[f][k]] <= nums[merge[f][l]] ) || l >= lend)
                    {
                        merge[t][m] = merge[f][k++];
                        ret[merge[t][m++]] += sum;
                        //cout << "case1" << endl;
                    }
                    else
                    {
                        int tmp = merge[f][l++];
                        merge[t][m++] = tmp;
                        sum++;
                        //cout << "case2" << endl;
                    }
                }
/*
                for(int i = 0; i < merge[f].size(); ++i)
                {
                    cout << merge[f][i] << "|";
                }
                cout << endl;

                for(int i = 0; i < merge[t].size(); ++i)
                {
                    cout << merge[t][i] << "|";
                }
                cout << endl;
*/
            }

            for(int i = 0; i < ret.size(); ++i)
            {
                cout << ret[i] << "|";
            }
            cout << endl;

            f = (f+1)%2;
        }

        return ret;
    }

    
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(5);
   // nums.push_back(1);

    vector<int> ret = s.countSmaller(nums);

    return 0;
}
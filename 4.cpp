/*
    处理问题思路要清晰,这里就是说要定主调,二分枚举,先刨除边界情况,然后二分处理,注意下标越界
    ifelse条件分类要明确,不左移不右移不就是正经答案吗
*/

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int start = 0, end = n1 - 1;
        int i = 0, j = 0;
        double ret = 0;

        for(int i = 0; i < n1; ++i)
            cout << nums1[i] << ",";
        cout << endl;

        for(int i = 0; i < n2; ++i)
            cout << nums2[i] << ",";
        cout << endl;

        if(n1 == 0)
        {
            if(n2 % 2 == 1)
            {
                return nums2[(n2-1)/2];
            }
            else
            {
                return ( nums2[(n2-1)/2] + nums2[(n2-1)/2 + 1] ) / 2.0;
            }
        }

        if(n2 == 0)
        {
            if(n1 % 2 == 1)
            {
                return nums1[(n1-1)/2];
            }
            else
            {
                return  (nums1[(n1-1)/2] + nums1[(n1-1)/2 + 1] ) / 2.0;
            }
        }

        //此处判断有误
        //if(n2 >= n1)
        {
            int j = (n1 + n2) / 2 - 1;
            //这个是主要条件
            //前边的条件后来加的
            if(j <= n2-1 && nums2[j] <= nums1[0])
            {
                if( (n1 + n2) % 2 == 1)
                {
                    ret = (double)min(nums1[0], (j+1 <= n2 -1 ? nums2[j+1]:210000000));
                    cout << "ret:" << ret << endl;
                    return ret;
                }
                else
                {
                    ret = ( nums2[j] + (double)min(nums1[0], (j+1 <= n2-1 ? nums2[j+1]:210000000) ) ) / 2.0;
                    cout << "ret:" << ret << endl;
                    return ret;
                }
            }
        }

        //要考虑二分是否能穷尽所有的情况
        //n1+n2是奇数怎么办
        //考虑下一个数组太小不够分的情况
        do
        {
            i = (start + end) / 2;
            j = (n1 + n2) / 2 - (i + 1) - 1;
            cout << start << "|" << end << "|" << i <<  "|" << j << endl;
            
            //左右移越界的情况没有考虑过
            //原来是0
            if(j < -1)
            {
                end = i;
                continue;
            }
            else if(j >= n2)
            {
                start = i + 1;
                continue;
            }

            //此处没用=是可以的
            //区间左移
            //i的值倒不用检查
            if(j + 1 <= n2 - 1 && nums1[i] > nums2[j+1])
            {
                //i已经被考察过了,可以继续看比i小的
                end = i;
                //接近0时的特殊情况
            }
            //j在-1的情况下leetcode会报错,本地不会
            //如果j=-1,不会继续左移,循环结束了,会进入下个条件分支
            else if(j <= n2 - 1 && j >= 0 && i+1 <= n1 -1 && nums2[j] > nums1[i+1])
            {
                start = i + 1;
                //接近尾部的情况
            }
            else
            {
                if( (n1 + n2) % 2 == 1)
                {
                    ret = (double)min( (i+1<=n1-1? nums1[i+1] : 210000000), (j+1<=n2-1 ? nums2[j+1]: 210000000));
                    cout << "ret:" << ret << endl;
                    return ret;
                }
                else
                {
                    ret = ( (double)max((i >=0 ? nums1[i] : -210000000), (j >=0&&j<=n2-1 ? nums2[j] : -210000000) ) + (double)min( (i+1 > n1-1 ? 210000000 : nums1[i+1]), (j+1 > n2-1 ? 210000000 : nums2[j+1])) ) / 2;
                    cout << "ret:" << ret << endl;
                    return ret;
                }
            }

        }
        //这么写你得保证能找到一个值
        while(1);

        return 0;
    }
};

int main()
{
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    //nums1.push_back(5);
    //nums1.push_back(7);
    //nums1.push_back(9);
    //nums1.push_back(11);

    nums2.push_back(3);
    nums2.push_back(4);
    //nums2.push_back(6);
    //nums2.push_back(8);

    Solution s;
    s.findMedianSortedArrays(nums1, nums2);


    return 0;
}
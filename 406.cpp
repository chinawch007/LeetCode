#include<vector>
#include<algorithm>

using namespace std;

struct node
    {
        node(){};
        node(int h, int k) : h(h), k(k) {};
        int h;
        int k;
        bool operator()(struct node n)
        {
            return h > n.h || (h == n.h && k < n.k);
        }
    };

    bool cmp(node x, node y)
    {
        return x.h > y.h || (x.h == y.h && x.k < y.k);
    };

class Solution {
public:
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        vector<node> v;
        vector<node> vOut;
        vector<vector<int> > vRet;

        /*
        vector<int> vec;
        vec.push_back(0);
        vec.insert(vec.begin(), 1);
        */

        for(int i = 0; i < people.size(); ++i)
        {
            node n(people[i][0], people[i][1]);
            v.push_back(n);
        }

        sort(v.begin(), v.end(), cmp);
        
        for(int i = 0; i < v.size(); ++i)
        {
            vOut.insert(v.begin(), v[i]);
            //vOut.insert(v.begin() + v[i].k, v[i]);
            
        }

        for(int i = 0; i < vOut.size(); ++i)
        {
            vector<int> tmp;
            tmp.push_back(vOut[i].h);
            tmp.push_back(vOut[i].k);

            vRet.push_back(tmp);
        }

        return vRet;


    }
};

int main()
{
    Solution s;
    vector<int> v1;
    v1.push_back(7);
    v1.push_back(0);
    vector<vector<int> > v;
    v.push_back(v1);

    s.reconstructQueue(v);

    return 0;
}
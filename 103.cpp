#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void reverse(vector<int>& v)
{
    vector<int> ret;

    for(int i = 0; i < v.size(); ++i)
    {
        ret.push_back(v[v.size() - 1 - i]);
    }

    v = ret;
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)return ret;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;

        TreeNode* t;
        while(q.size() > 0)
        {
            t = q.front();
            q.pop();

            if(t != NULL)
            {
                v.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            else
            {
                ret.push_back(v);
                v.clear();

                if(q.size() > 0)q.push(NULL);
            }
        }

        for(int i = 1; i < ret.size(); i += 2)
        {
            reverse(ret[i]);
        }

        return ret;
    }
};

int main()
{
    Solution s;

    

    return 0;
}
#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;

        int mi = INT32_MAX;
        int ma = INT32_MIN;
        int ret = 0;

        root->val = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int level = 1;
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();

            if(p)
            {
                if(p->val < mi)mi = p->val;
                if(p->val > ma)ma = p->val;
                
                //靠，总是乘2超限了
                if(p->left){p->left->val = 2 * p->val - (mi == INT32_MAX ? 0 : mi);q.push(p->left);}
                if(p->right){p->right->val = 2 * p->val + 1 - (mi == INT32_MAX ? 0 : mi);q.push(p->right);}
            }
            //新一层级
            //大哥你发没发现你这样的话是无限的了...
            else
            {
                ++level;
                if(!q.empty())q.push(NULL);
                if(ma - mi + 1> ret)ret = ma - mi + 1;
                mi = INT32_MAX;
                ma = INT32_MIN;
            }
        }

        return ret;
    }
};
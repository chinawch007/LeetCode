/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* n, int& max, int& min, TreeNode** parent)
    {
        trans = false;
        max = n->val;
        min = n->val;
        int lmax = -1, lmin = 100;
        int rmax = -1, rmin = 100;

        if(n->left && dfs(n->left, lmax, lmin, &n))
        {
            return true;
        }

        if(n->left && lmax <= V && n->val > V)
        {
            ret.push_back(root);
            ret.push_back(n->left);
            return true;
        }

        if(n->right && dfs(n->right, rmax, rmin, &n))
        {
            return true;
        }

        //右子树链接破坏情形要复杂些，要嫁接
        if(n->right && n->val <= V && n->right->val > V)
        {
            ret.push_back(root);
            ret.push_back(n);
            
        }

        if(rmax > max)max = rmax;
        if(lmin < min)min = lmin;
    }

    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        this->V = V;
        this->root = root;
        int min, max;
        TreeNode** parent = NULL;
        dfs(root, max, min, parent);
    }

    TreeNode* dest;
    TreeNode* root;
    int V;
    vector<TreeNode*> ret;
};
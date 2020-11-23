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

    void dfs(TreeNode* n, int& maxSelf)//引用是次节点为终点的最大路径
    {
        maxSelf = n->val;
        int maxl = 0, maxr = 0;
        if(n->left)dfs(n->left, maxl);
        if(n->right)dfs(n->right, maxr);

        if(n->val + maxl > maxSelf)maxSelf = n->val + maxl;
        if(n->val + maxr > maxSelf)maxSelf = n->val + maxr;
        if(n->val > max)max = n->val;
        if(n->val + maxl > max)max = n->val + maxl;
        if(n->val + maxr > max)max = n->val + maxr;
        if(n->val + maxl + maxr > max)max = n->val + maxl + maxr;
    }

    int maxPathSum(TreeNode* root) {
        int maxSelf;
        dfs(root, maxSelf);
        return max;
    }

    int max = -10000;
};
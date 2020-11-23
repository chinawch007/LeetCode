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
    TreeNode* dfs(int k, int s, int e, vector<int>& preorder, vector<int>& inorder)
    {
        if(k == len)return NULL;
        if(s>e)return NULL;
        TreeNode* n = new TreeNode(preorder[k]);

        int pos = mPos[preorder[k]];
        n->left = dfs(k+1, s, pos-1, preorder, inorder);
        n->right = dfs(k+pos-s+1, pos+1, e, preorder, inorder);

        return n;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        len = preorder.size();

        for(int i = 0; i < len; ++i)
        {
            mPos[inorder[i]] = i;
        }

        return dfs(0, 0, len-1, preorder, inorder);
    }

    int len;
    map<int, int> mPos;
};
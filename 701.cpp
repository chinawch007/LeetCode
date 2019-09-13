#include<vector>
#include<string>
#include<map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(val > root->val)
        {
            if(root->right)
            {
                insertIntoBST(root->right, val);
            }
            else
            {
                TreeNode* p = new TreeNode(val);
                root->right = p;
            }
        }
        else
        {
            if(root->left)
            {
                insertIntoBST(root->left, val);
            }
            else
            {
                TreeNode* p = new TreeNode(val);
                root->left = p;
            }
        }
        
        return root;
    }
};
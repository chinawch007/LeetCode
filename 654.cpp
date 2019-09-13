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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0)return NULL;
        
        TreeNode* root = new TreeNode(0);
        
        root->val = nums[0];
        root->left = NULL;
        root->right = NULL;
        
        for(int i = 1; i < sz; ++i)
        {
            TreeNode* n = new TreeNode(0);
            
            n->val = nums[i];
            n->left = n->right = NULL;
            
            TreeNode* p = root;
            TreeNode* pre = NULL;
            
            while(p)
            {   
                if(p->val < nums[i])break;
                pre = p;
                p = p->right;
            }
            
            if(!pre)
            {
                n->left = root;
                root = n;
            }
            else
            {
                pre->right = n;
                n->left = p;
            }
        }
        
        return root;
    }
};
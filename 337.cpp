class Solution {
public:
    void dp(TreeNode* p, int& yes, int& no)
    {
        //他这个初始值设置容易些，直接都0就可以了
        int leftYes = 0, leftNo = 0, rightYes = 0, rightNo = 0;
        
        if(p->left)
        {
            dp(p->left, leftYes, leftNo);   
        }
        
        if(p->right)
        {
            dp(p->right, rightYes, rightNo);
        }
        
        yes = leftNo + rightNo + p->val;
        no = max(leftYes + rightYes, leftYes + rightNo);
        no = max(no, leftNo + rightYes);
        no = max(no, leftNo + rightNo);
        //不考虑都是no的情况了，节点都是正数的话没问题
    }
    
    int rob(TreeNode* root) {
        if(!root)return 0;
        int yes, no;
        dp(root, yes, no);
        return max(yes, no);
    }
};

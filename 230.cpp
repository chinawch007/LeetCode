class Solution {
public:
    //返回此树的节点数
    int search(TreeNode* p, int k)
    {
        int sum = 0;
        
        if(p->left)
        {
            sum = search(p->left, k);
            k -= sum;
        }
        
        if(k == 1)
        {
            ret = p->val;
        }
        --k;
        ++sum;
        
        if(p->right)
        {
            int t = search(p->right, k);
            sum += t;
            k -= t;
        }
        
        return sum;
    }
        
    int kthSmallest(TreeNode* root, int k) {
        ret = 0;
        search(root, k);
        return ret;
    }
    
    int ret;
};

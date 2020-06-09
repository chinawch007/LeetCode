//我原来设置两个bool值，第一次碰到两个都为true就是最近公共祖先。。。
class Solution {
public:
    bool search(TreeNode* n, TreeNode* p, TreeNode* q)
    {
        bool bLeft, bRight, bRet;
        bLeft = bRight = bRet = false;
        
        if(n->left)
        {
            bLeft = search(n->left, p, q);
        }
        
        if(n->right)
        {
            bRight = search(n->right, p, q);
        }
        
        if(n == p || n == q)
        {
            bRet = true;
        }

        if( (bLeft && bRight) || (bLeft && bRet) || (bRet && bRight) )
        {
            if(!bCopy)
            {
                ret = n;
                bCopy = true;
            }
            
        }
        
        return (bRet || bLeft || bRight);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bCopy = false;
        search(root, p, q);
        return ret;
    }
    
    TreeNode* ret;
    bool bCopy;
};

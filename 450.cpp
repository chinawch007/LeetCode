class Solution {
public:
    //不用真删除节点迁移指针，换值就行了
    //返回值表示刚刚递归的节点是不是叶子节点
    void del(TreeNode* p, TreeNode* parent)
    {
        if(!p->left && !p->right)
        {
            if(parent->left == p)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        
        TreeNode* n;
        TreeNode* np;
        if(p->left)
        {
            n = p->left;
            np = p;
            
            while(n->right)
            {
                np = n;
                n = n->right;
            }
            
            p->val = n->val;
            del(n, np);
        }
        else if(p->right)
        {
            n = p->right;
            np = p;
            
            while(n->left)
            {
                np = n;
                n = n->left;
            }
            
            p->val = n->val;
            del(n, np);
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = root;
        TreeNode* parent;
        int direct = 0;
        if(!p)return root;
        
        while(p)
        {
            if(p->val == key)break;
            
            if(key < p->val)
            {
                parent = p;
                p = p->left;
            }
            else if(key > p->val)
            {
                parent = p;
                p = p->right;
            }
        }
        
        if(!p)return root;
        
        if(p == root && !p->left && !p->right)return NULL;
        
        del(p, parent);
        
        return root;
    }
};

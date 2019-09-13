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
    //返回个先遍历
    //注意空叶子也要算在内，不然会混淆
    string oper(TreeNode* t)
    {
        if(!t)return string("x");
        string ret;
        ret.push_back( (char)(t->val) );
        ret += oper(t->left);
        ret += oper(t->right);
        
        if( ms.find(ret) != ms.end() )
        {
            if(!ms[ret])
            {    
                ms[ret] = true;
                result.push_back(t);
            }
        }
        else
        {
            ms[ret] = false;
        }    
        
        return ret;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root)return result;
        oper(root);
        return result;
    }
    
    map<string, bool> ms;
    vector<TreeNode*> result;
};
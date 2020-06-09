#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int level1 = 0, level2 = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        if(!root)return true;

        int level = 1;
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();

            if(p)
            {
                if(p->left)
                {
                    if(level == level1 || level == level2)return false;
                    q.push(p->left);
                }
                else
                {

                    if(level1 == 0)
                    {
                        level1 = level;
                        level2 = level + 1;
                    }
                    else if(level == level1)
                    {

                    }
                    else if(level == level2)
                    {

                    }
                }

                if(p->right)
                {
                    if(level == level1 || level == level2)return false;
                    q.push(p->right);
                }
                else
                {

                    if(level1 == 0)
                    {
                        level1 = level;
                        level2 = level + 1;
                    }
                    else if(level == level1)
                    {

                    }
                    else if(level == level2)
                    {

                    }
                }
            }
            else
            {
                if(!q.empty())q.push(NULL);
                level++;
            }
        }

        return true;

    }
};
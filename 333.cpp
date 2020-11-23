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
    bool dfs(TreeNode* t, int& min, int& max, int& cnt)
    {
        bool bl, br;
        int mil = 1000000, mir = 1000000, mal = -1000000, mar = -1000000, cntl = 0, cntr = 0; 

        if(t->left)
        {
            bl = dfs(t->left, mil, mal, cntl);
        }
        else 
        {
            bl = true;
        }

        if(t->right)
        {
            br = dfs(t->right, mir, mar, cntr);
        }
        else
        {
            br = true;
        }

        max = t->val;
        if(mal > max)max = mal;
        if(mar > max)max = mar;

        min = t->val;
        if(mil < min)min = mil;
        if(mir < min)min = mir;

        cnt = cntl + cntr + 1;

        cout << t->val << "|" << bl <<"|" << br << "|" << mal << "|" << mir << endl;

        if(bl && br && t->val > mal && t->val < mir)
        {
            if(cnt > maxCnt)maxCnt = cnt;
            return true;
        }
        else
        {
            return false;
        }

    }

    int largestBSTSubtree(TreeNode* root) {
        cout << "fuck" << endl;

        if(!root)return 0;

        maxCnt = 0;
        int max, min, cnt;
        dfs(root, min, max, cnt);

        return maxCnt;
    }

    int maxCnt;
};
class Solution {
public:
    void dp(TreeNode* p, int& yes, int&mid, int& no)
    {
        //怎么想清楚这个赋值的道理呢
        int leftYes=0, leftMid=20000, leftNo=20000, rightYes=0, rightMid=20000, rightNo=20000;
        
        if(!p->left && !p->right)
        {
            yes = 1;
            mid = 20000;
            no = 0;
            cout << yes << "|" << mid << "|" << no << endl;
            return;
        }
        
        if(p->left)
        {
            dp(p->left, leftYes, leftMid, leftNo);
            if(!p->right)
            {
                yes = min(leftYes+1, leftMid+1);
                yes = min(yes, leftNo+1);
                
                mid = leftYes;
                
                no = leftMid;
                cout << yes << "|" << mid << "|" << no << endl;
                return;
            }
        }
        
        if(p->right)
        {
            dp(p->right, rightYes, rightMid, rightNo);
            if(!p->left)
            {
                yes = min(rightYes+1, rightMid+1);
                yes = min(yes, rightNo+1);
                
                mid = rightYes;
                
                no = rightMid;
                cout << yes << "|" << mid << "|" << no << endl;
                return;
            }
        }

        //cout << leftYes << "|" << leftMid << "|" << leftNo << "|" << rightYes << "|" << rightMid << "|" << rightNo << "|" << endl; 
        
        yes = min(leftYes+rightYes+1, leftYes+rightNo+1);
        yes = min(yes, leftYes+rightMid+1);
        yes = min(yes, leftMid+rightYes+1);
        yes = min(yes, leftMid+rightMid+1);
        yes = min(yes, leftMid+rightNo+1);
        yes = min(yes, leftNo+rightYes+1);
        yes = min(yes, leftNo+rightMid+1);
        yes = min(yes, leftNo+rightNo+1);
        
        mid = min(leftYes+rightMid, leftMid+rightYes);
        mid = min(mid, leftYes+rightYes);
        
        //这么写有错误啊
        no = leftMid + rightMid;
        
        cout << yes << "|" << mid << "|" << no << endl;
        
    }
    
    int minCameraCover(TreeNode* root) {
        int yes, mid, no;
        dp(root, yes, mid, no);
        int mi = min(yes, mid);
        return mi;
    }
};

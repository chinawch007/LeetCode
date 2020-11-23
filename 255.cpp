class Solution {
public:
    //因为是先序遍历，当前节点是此一小段字符串子树的根节点
    bool dfs(int n, int& last, int min, int max)
    {
        if(n >= nodes.size())return true;

        //对左右子树根节点大小做比较讨论
        //---讨论所有正常情况，其余的都是错误情况
        if(n+1 >= nodes.size())
        {
            last = n;
            return true;
        }
        else if(nodes[n+1] < nodes[n] &&  nodes[n+1] > min )
        {
            int tmpMax;
            if(nodes[n] < max)tmpMax = nodes[n];
            else tmpMax = max;
            if(!dfs(n+1,last, min, tmpMax))return false;

            if(last+1 >= nodes.size()){
                return true;
            }
            if(nodes[last+1] > nodes[n] && nodes[last+1] < max){
                int tmp;
                if(nodes[n] > min)tmp = nodes[n];
                else tmp = min;
                if(!dfs(last+1, last, tmp, max))return false; 
            }
            else if(nodes[last+1] > nodes[n] && nodes[last+1] > max)
            {
                //last = n;
                return true;
            }
            else 
            {
                return false;
            }
        }
        else if(nodes[n+1] > nodes[n] && nodes[n+1] < max)
        {
            int tmp;
            if(nodes[n] > min)tmp = nodes[n];
            else tmp = min;
            if(!dfs(n+1, last, tmp, max))return false; 
        }
        else if(nodes[n+1] > nodes[n] && nodes[n+1] > max)//因为树构成的单调性，没有相反的情况
        //这里是递归调用末端的情况
        {
            last = n;
            return true;
        }
        else
        {
            return false;
        }

        //此时last应该是被右子树设置好了
        return true;
    }

    bool verifyPreorder(vector<int>& preorder) {
        nodes = preorder;
        int last = 0;
        return dfs(0, last,  0, 10000000);
    }

    vector<int> nodes;
};
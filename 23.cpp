#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class cmp
{
    public:
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;

        ListNode* ret = NULL, *tail = NULL;

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        
        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i] == NULL)continue;
            q.push(lists[i]);
        }

        ListNode* t;
        while(q.size() > 0)
        {
            t = q.top();
            q.pop();
            //cout << t->val << endl;

            if(t->next != NULL)
            {
                q.push(t->next);
            }

            if(ret == NULL)
            {
                ret = t;
                tail = t;
            }
            else
            {
                tail->next = t;
                tail = t;
            }

        }
        return ret;
    }
};

int main()
{
    Solution s;

    

    return 0;
}
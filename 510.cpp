// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right)
        {
            Node* n = node->right;
            while(n->left)n = n->left;
            return n;
        }
        else if(node->parent && node->parent->left == node)
        {
            return node->parent;
        }
        else if(node->parent && node->parent->right == node)
        {
            Node* p = node;
            while(p->parent && p->parent->right == p)p = p->parent;

            //根节点
            if(!p->parent)
            {
                return NULL;
            }
            else//是父节点的左子
            {
                return p->parent;
            }
        }
        else
        {
            return NULL;
        }
    }
};
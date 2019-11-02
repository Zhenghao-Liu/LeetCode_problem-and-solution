/*
* 前提是所有节点的的next都默认为NULL
* 采用BFS的方法
* 记录每一行的最左边节点，然后用next来代替queue的关系即可
* 同样是操作每一行的对应节点的下左右子节点
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root==NULL)
            return NULL;
        Node *begin_of_line=root,*p;
        while (begin_of_line->left!=NULL)
        {
            p=begin_of_line;
            while(p!=NULL)
            {
                p->left->next=p->right;
                if (p->next!=NULL)
                    p->right->next=p->next->left;
                p=p->next;
            }
            begin_of_line=begin_of_line->left;
        }
        return root;
    }
};

//将图片顺时针旋转90度，就是一颗二叉树，dfs遍历节点
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    vector<int> helper;
public:
    Node* flatten(Node* head) {
        if (head==NULL)
            return head;
        helper.clear();
        helper.reserve(1e5+1);
        dfs(head);
        Node *dummy=new Node;
        Node *p=dummy;
        for (int &i:helper)
        {
            p->next=new Node;
            p->next->val=i;
            p->next->prev=p;
            p->next->next=NULL;
            p->next->child=NULL;
            p=p->next;
        }
        dummy->next->prev=NULL;
        return dummy->next;
    }
    void dfs(Node *p)
    {
        if (p==NULL)
            return;
        helper.push_back(p->val);
        dfs(p->child);
        dfs(p->next);
    }
};

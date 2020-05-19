//将第二层先放到第一层，再接着遍历，那么如果有第三层会变成第二层，依次类推，但最坏可到达O(N^2)
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
public:
    Node* flatten(Node* head) {
        Node *p=head;
        while (p!=NULL)
        {
            if (p->child!=NULL)
            {
                Node * original_p_next=p->next;
                p->next=p->child;
                p->next->prev=p;
                p->child=NULL;
                Node *q=new Node;
                q->next=p->next;
                while (q->next!=NULL)
                    q=q->next;
                q->next=original_p_next;
                if (original_p_next!=NULL)
                    original_p_next->prev=q;
            }
            p=p->next;
        }
        return head;
    }
};

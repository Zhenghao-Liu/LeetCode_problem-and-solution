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
        if (head==NULL)
            return NULL;
        Node *p=head;
        while (p!=NULL && p->child==NULL)
            p=p->next;
        if (p==NULL)
            return head;
        Node * wanted_next=p->next;
        Node * p_child_last=helper(p->child);
        p->next=p->child;
        p->child->prev=p;
        p->child=NULL;
        p_child_last->next=wanted_next;
        if (wanted_next!=NULL)
            wanted_next->prev=p_child_last;
        return head;
    }
    Node* helper(Node * root)
    {
        Node *p=root;
        Node *p_pre=new Node;
        p_pre->next=p;
        while (p!=NULL && p->child==NULL)
        {
            p=p->next;
            p_pre=p_pre->next;
        }
        if (p==NULL)
            return p_pre;
        Node * wanted_next=p->next;
        Node * p_child_last=helper(p->child);
        p->next=p->child;
        p->child->prev=p;
        p->child=NULL;
        p_child_last->next=wanted_next;
        if (wanted_next!=NULL)
            wanted_next->prev=p_child_last;
        else
            return p_child_last;
        while (wanted_next->next!=NULL)
            wanted_next=wanted_next->next;
        return wanted_next;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL)
            return NULL;
        Node * root=new Node(head->val,NULL,NULL);
        unordered_map<Node*,Node*> list_map;
        list_map.insert({head,root});
        Node * p=root,*q=head->next;
        while (q!=NULL)
        {
            p->next=new Node(q->val,NULL,NULL);
            p=p->next;
            list_map.insert({q,p});
            q=q->next;
        }
        p=root;
        q=head;
        //因为random可能指向空节点
        list_map.insert({NULL,NULL});
        while (p!=NULL)
        {
            p->random=list_map.at(q->random);
            p=p->next;
            q=q->next;
        }
        return root;
    }
};

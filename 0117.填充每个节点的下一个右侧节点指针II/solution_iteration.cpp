//参考上一题的迭代法
/*
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
        Node *begin_of_line=root,*begin_of_next_line;
        bool judge_recorded=true;
        Node *p,*q;
        int index;
        while (judge_recorded)
        {
            p=begin_of_line;
            judge_recorded=false;
            while(p!=NULL)
            {
                if (p->left!=NULL)
                {
                    q=p;
                    index=0;
                    while (q!=NULL)
                    {
                        if (index%2==0)
                        {
                            if (q->right!=NULL)
                            {
                                p->left->next=q->right;
                                break;
                            }   
                            else
                            {
                                q=q->next;
                                ++index;
                            }    
                        }       
                        else 
                        {
                            if (q->left!=NULL)
                            {
                                p->left->next=q->left;
                                break;
                            }   
                            else
                                ++index;
                        }
                    }
                    if (!judge_recorded)
                    {
                        begin_of_next_line=p->left;
                        judge_recorded=true;
                    }   
                }
                if (p->next!=NULL && p->right!=NULL)
                {
                    q=p->next;
                    index=0;
                    while (q!=NULL)
                    {
                        if (index%2==0)
                        {
                            if (q->left!=NULL)
                            {
                                p->right->next=q->left;
                                break;
                            }
                            else
                                ++index;
                        }
                        else
                        {
                            if (q->right!=NULL)
                            {
                                p->right->next=q->right;
                                break;
                            }
                            else
                            {
                                q=q->next;
                                ++index;
                            }  
                        } 
                    }
                    if (!judge_recorded)
                    {
                        begin_of_next_line=p->right;
                        judge_recorded=true;
                    }  
                }
                if (p->next==NULL && p->right!=NULL && !judge_recorded)
                {
                    begin_of_next_line=p->right;
                    judge_recorded=true;
                }
                p=p->next;
            }
            begin_of_line=begin_of_next_line;
        }
        return root;
    }
};

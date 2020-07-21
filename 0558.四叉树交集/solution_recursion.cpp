/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool choose_val=false;
public:
    Node* intersect(Node* q1, Node* q2) {
        if (q1==NULL && q2==NULL)
            return NULL;
        if (q1->isLeaf)
        {
            if (q1->val)
                return new Node(true,true);
            else
                return q2;
        }
        else if (q2->isLeaf)
        {
            if (q2->val)
                return new Node(true,true);
            else
                return q1;
        }
        Node * cur_top_left=intersect(q1->topLeft,q2->topLeft);
        Node * cur_top_right=intersect(q1->topRight,q2->topRight);
        Node * cur_bottom_left=intersect(q1->bottomLeft,q2->bottomLeft);
        Node * cur_bottom_right=intersect(q1->bottomRight,q2->bottomRight);
        //注意有可能四个叶子或之后都是1，那么应该合成一个大的叶子节点且val是1
        if (cur_top_left->isLeaf && cur_top_right->isLeaf && cur_bottom_left->isLeaf && cur_bottom_right->isLeaf 
            && cur_top_left->val && cur_top_right->val && cur_bottom_left->val && cur_bottom_right->val)
            return new Node(true,true);
        //else
        return new Node (choose_val,false,cur_top_left,cur_top_right,cur_bottom_left,cur_bottom_right); 
    }
};

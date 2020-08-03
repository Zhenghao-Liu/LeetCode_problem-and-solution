//前序顺序：根左右，那么存children时候就应该逆序存，这样子先出栈的就是最左边的孩子
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> ans;
        s.push(root);
        while (!s.empty())
        {
            Node *p=s.top();
            s.pop();
            if (p!=NULL)
                ans.push_back(p->val);
            else
                continue;
            for (int i=(p->children).size()-1;i>=0;--i)
                s.push((p->children).at(i));
        }
        return ans;
    }
};

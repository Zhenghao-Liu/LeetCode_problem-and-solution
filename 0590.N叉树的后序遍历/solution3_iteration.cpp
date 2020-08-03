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
//后序遍历：左右根，可以看成是根右左的逆序
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root==NULL)
            return {};
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty())
        {
            Node *p=s.top();
            ans.push_back(p->val);
            s.pop();
            int size=(p->children).size();
            for (int i=0;i<size;++i)
                s.push((p->children).at(i));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

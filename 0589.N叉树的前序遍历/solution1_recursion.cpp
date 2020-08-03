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
    vector<int> ans;
public:
    vector<int> preorder(Node* root) {
        ans.clear();
        dfs(root);
        return ans;
    }
    void dfs(Node * n)
    {
        if (n==NULL)
            return;
        ans.push_back(n->val);
        for (Node * i:n->children)
            dfs(i);
    }
};

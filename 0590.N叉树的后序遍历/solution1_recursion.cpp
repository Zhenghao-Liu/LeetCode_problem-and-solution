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
    vector<int> postorder(Node* root) {
        if (root==NULL)
            return {};
        ans.clear();
        dfs(root);
        return ans;
    }
    void dfs(Node * p)
    {
        int size=(p->children).size();
        for (int i=0;i<size;++i)
            dfs((p->children).at(i));
        ans.push_back(p->val);
    }
};

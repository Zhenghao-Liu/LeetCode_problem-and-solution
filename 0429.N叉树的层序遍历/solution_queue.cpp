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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> helper;
        if (root!=NULL)
            helper.push(root);
        else
            return ans;
        int level=-1;
        while (!helper.empty())
        {
            int helper_size=helper.size();
            ans.push_back({});
            ++level;
            while (helper_size>0)
            {
                Node *p=helper.front();
                ans.at(level).push_back(p->val);
                helper.pop();
                for (Node * i:p->children)
                    helper.push(i);
                --helper_size;
            }
        }
        return ans;
    }
};

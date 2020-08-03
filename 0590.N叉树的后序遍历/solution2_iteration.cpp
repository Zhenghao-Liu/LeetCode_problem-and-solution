//模拟二叉树的后序遍历，但是又不知道父节点是不是先前已经访问过，所以设置一个bool标志来判断是否已经访问过该节点
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
typedef pair<Node *,bool> pii;
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root==NULL)
            return {};
        vector<int> ans;
        stack<pii> s;
        s.push({root,false});
        while (!s.empty())
        {
            if (!s.top().second)
            {
                s.top().second=true;
                Node *p=s.top().first;
                int size=(p->children).size();
                for (int i=size-1;i>=0;--i)
                    s.push({(p->children).at(i),false});
            }
            else
            {
                ans.push_back((s.top().first)->val);
                s.pop();
            }
        }
        return ans;
    }
};

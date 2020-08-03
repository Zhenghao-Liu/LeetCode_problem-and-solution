//模拟二叉树的前序遍历，但是因为是N叉树，所以还要记录父节点中children遍历到的下标
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
typedef pair<Node*,int> pii;
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<pii> s;
        Node *p=root;
        while (!s.empty() || p!=NULL)
        {
            if (p!=NULL)
            {
                ans.push_back(p->val);
                if (!(p->children).empty())
                {
                    s.push({p,1});
                    p=(p->children).at(0);
                } 
                else
                    p=NULL;
            }
            else
            {
                p=s.top().first;
                int index=s.top().second;
                s.pop();
                if (index<(int)(p->children).size())
                {
                    s.push({p,index+1});
                    p=(p->children).at(index);
                }
                else
                    p=NULL;
            }
        }
        return ans;
    }
};

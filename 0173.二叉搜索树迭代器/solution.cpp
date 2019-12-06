/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> stack_roots;
    TreeNode * p;
public:
    BSTIterator(TreeNode* root) {
        p=root;
        push_left();
    }
    
    /** @return the next smallest number */
    int next() {
        p=stack_roots.top();
        stack_roots.pop();
        int answer=p->val;
        p=p->right;
        push_left();
        return answer;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (p==NULL && stack_roots.empty())
            return false;
        else
            return true;
    }

    void push_left()
    {
        while(p!=NULL)
        {
            stack_roots.push(p);
            p=p->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

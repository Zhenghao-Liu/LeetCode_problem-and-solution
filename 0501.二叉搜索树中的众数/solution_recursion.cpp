/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
    int max_count=0;
public:
    vector<int> findMode(TreeNode* root) {
        max_count=0;
        ans.clear();
        int count=0;
        TreeNode * prev=NULL;
        dfs(root,count,prev);
        return ans;
    }
    void dfs(TreeNode *node,int & count,TreeNode *& prev)
    {
        if (node==NULL)
            return;
        dfs(node->left,count,prev);
        if (prev!=NULL && node->val==prev->val)
            ++count;
        else
            count=1;
        if (count>=max_count)
        {
            if (count>max_count)
                ans.clear();
            max_count=count;
            ans.push_back(node->val);
        }
        prev=node;
        dfs(node->right,count,prev);
    }
};

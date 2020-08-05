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
    string ans;
public:
    string tree2str(TreeNode* t) {
        if (t==NULL)
            return "";
        ans.clear();
        dfs(t);
        return ans;
    }
    void dfs(TreeNode *node)
    {
        ans+=to_string(node->val);
        if (node->left!=NULL)
        {
            ans+="(";
            dfs(node->left);
            ans+=")";
        }
        if (node->right!=NULL)
        {
            if (node->left==NULL)
                ans+="()";
            ans+="(";
            dfs(node->right);
            ans+=")";
        }
    }
};

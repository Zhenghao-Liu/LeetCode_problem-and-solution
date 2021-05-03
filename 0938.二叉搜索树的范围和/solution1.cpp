/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
    int l,h;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans=0;
        l=low;
        h=high;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode *node) {
        stack<TreeNode *> sta;
        while (node!=NULL || !sta.empty()) {
            if (node!=NULL) {
                sta.push(node);
                node=node->left;
            } else {
                TreeNode *top=sta.top();
                sta.pop();
                if (top->val>=l && top->val<=h) {
                    ans+=top->val;
                }
                if (top->right!=NULL) {
                    node=top->right;
                }
            }
        }
    }
};
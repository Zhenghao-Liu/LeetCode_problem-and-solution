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
    vector<TreeNode*>vec;
public:
    TreeNode* increasingBST(TreeNode* root) {
        vec.clear();
        dfs(root);
        TreeNode * dummy=new TreeNode(-1);
        TreeNode * lst=dummy;
        for (TreeNode* i:vec) {
            lst->right=i;
            lst->left=NULL;
            lst=i;
        }
        lst->left=lst->right=NULL;
        return dummy->right;
    }
    void dfs(TreeNode * node) {
        stack<TreeNode *>sta;
        while (node!=NULL || !sta.empty()) {
            if (node!=NULL) {
                sta.push(node);
                node=node->left;
            } else {
                TreeNode *top=sta.top();
                sta.pop();
                vec.push_back(top);
                if (top->right!=NULL) {
                    node=top->right;
                }
            }
        }
    }
};
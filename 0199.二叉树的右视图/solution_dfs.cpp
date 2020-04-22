//先序遍历(根左右)则是每一层最左边的节点
//那么可以反过来(根右左)则是每一层最右边的节点
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
private:
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode *root,int depth)
    {
        if (root==NULL)
            return;
        if (depth==ans.size())
            ans.push_back(root->val);
        ++depth;
        dfs(root->right,depth);
        dfs(root->left,depth);
    }
};

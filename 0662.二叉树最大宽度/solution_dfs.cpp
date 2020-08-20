//完全二叉树，根节点为0，左孩子2i，右孩子2i+1，数据量过大所以用unsigned long long存序号
//dfs查找，用哈希表存储每一行最左边的节点的序号
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
 typedef unsigned long long ull;
class Solution {
    unordered_map<int,ull> start_index;
    ull ans;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root==NULL)
            return 0;
        start_index.clear();
        ans=1;
        dfs(root,1,0);
        return ans;
    }
    void dfs(TreeNode *node,int depth,ull index)
    {
        if (node==NULL)
            return;
        if (start_index.find(depth)==start_index.end())
            start_index[depth]=index;
        else
            ans=max(ans,index-start_index.at(depth)+1);
        dfs(node->left,depth+1,index*2);
        dfs(node->right,depth+1,index*2+1);
    }
};

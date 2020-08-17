//将二叉树序列化，并将结果放进哈希表中统计出现次数
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
    unordered_map<string,int> count;
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        count.clear();
        ans.clear();
        dfs(root);
        return ans;
    }
    string dfs(TreeNode *node)
    {
        if (node==NULL)
            return "#";
        string cur=to_string(node->val)+" "+dfs(node->left)+" "+dfs(node->right);
        ++count[cur];
        if (count.at(cur)==2)
           ans.push_back(node);
        return cur;
    }
};

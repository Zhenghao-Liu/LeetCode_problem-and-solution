//转换成左右叶子结点的深度递归
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
    int distance;
public:
    int countPairs(TreeNode* root, int _distance) {
        ans=0;
        distance=_distance;
        dfs(root);
        return ans;
    }
    vector<int> dfs(TreeNode *root)
    {
        if (root==NULL)
            return {};
        if (root->left==NULL && root->right==NULL)
            return {1};
        vector<int> left=dfs(root->left);
        vector<int> right=dfs(root->right);
        for (int i:left)
            for (int j:right)
                if (i+j<=distance)
                    ++ans;
        vector<int> ans;
        ans.reserve(left.size()+right.size());
        for (int &i:left)
            if (i+1<distance)
                ans.push_back(i+1);
        for (int i:right)
            if (i+1<distance)
                ans.push_back(i+1);
        return ans;
    }
};

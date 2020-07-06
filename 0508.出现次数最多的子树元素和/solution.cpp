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
    //first存子树元素和，second存出现次数
    unordered_map<int,int> count;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        count.clear();
        dfs(root);
        vector<int> ans;
        int max_count=INT_MIN;
        for (auto &i:count)
        {
            if (i.second>max_count)
            {
                ans.clear();
                max_count=i.second;
                ans.push_back(i.first);
            }
            else if (i.second==max_count)
                ans.push_back(i.first);
        }
        return ans;
    }
    int dfs(TreeNode *root)
    {
        if (root==NULL)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        int sum=left+right+root->val;
        ++count[sum];
        return sum;
    }
};

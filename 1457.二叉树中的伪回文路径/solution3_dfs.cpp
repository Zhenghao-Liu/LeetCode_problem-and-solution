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
    vector<int> count;
    int ans;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        count=vector<int>(10,0);
        ans=0;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root)
    {
        if (root==NULL)
            return;
        ++count[root->val];
        if (root->left==NULL && root->right==NULL)
            check_palindrome();
        dfs(root->left);
        dfs(root->right);
        --count[root->val];
    }
    void check_palindrome()
    {
        bool judge=true;
        bool judge_single=false;
        for (int &i:count)
        {
            if (i%2==0)
                continue;
            else if (!judge_single)
                judge_single=true;
            else
            {
                judge=false;
                break;
            }
        }
        if (judge)
            ++ans;
    }
};

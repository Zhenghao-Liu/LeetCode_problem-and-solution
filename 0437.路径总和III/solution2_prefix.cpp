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
    //key=从根到某节点的路径总值，value为该值在路径上出现了多少次
    unordered_map<int,int> helper;
public:
    int pathSum(TreeNode* root, int sum) {
        helper.clear();
        helper[0]=1;
        int cur=0;
        int ans=0;
        dfs(root,sum,cur,ans);
        return ans;
    }
    void dfs(TreeNode *root,const int &sum,int &cur,int &ans)
    {
        if (root==NULL)
            return;
        cur+=root->val;
        if (helper.find(cur-sum)!=helper.end())
            ans+=helper.at(cur-sum);
        ++helper[cur];
        dfs(root->left,sum,cur,ans);
        dfs(root->right,sum,cur,ans);
        --helper[cur];
        cur-=root->val;
        return;
    }
};

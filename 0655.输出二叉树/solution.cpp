/*
* 输出是一个m*n的二维数组
* 显然m就是二叉树的深度，n就是2^m-1，即(1<<m)-1
* 通过双指针方式固定ans.at(row)的左边界和右边界进行模拟即可
*/
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
    vector<vector<string>> ans;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if (root==NULL)
            return {};
        int depth=max_depth(root);
        ans=vector<vector<string>>(depth,vector<string>((1<<depth)-1));
        dfs(root,0,0,(1<<depth)-2);
        return ans;
    }
    int max_depth(TreeNode * node)
    {
        if (node==NULL)
            return 0;
        return 1+max(max_depth(node->left),max_depth(node->right));
    }
    void dfs(TreeNode *node,int row,int start,int end)
    {
        if (node==NULL)
            return;
        int mid=(start+end)/2;
        ans.at(row).at(mid)=to_string(node->val);
        dfs(node->left,row+1,start,mid-1);
        dfs(node->right,row+1,mid+1,end);
    }
};

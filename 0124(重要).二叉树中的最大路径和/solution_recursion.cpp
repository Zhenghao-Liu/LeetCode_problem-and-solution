/*
* 二叉树 abc，a 是根结点（递归中的 root），bc 是左右子结点（代表其递归后的最优解）。
* 最大的路径，可能的路径情况：
*    a
*   / \
*  b   c
* 1.b + a + c。
* 2.b + a + a 的父结点。
* 3.a + c + a 的父结点。
* 另外结点有可能是负值，最大和肯定就要想办法舍弃负值（max(0, x)）
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
public:
    int maxPathSum(TreeNode* root) {
        int answer=INT_MIN;
        find_maxPathSum(root,answer);
        return answer;
    }
    int find_maxPathSum(TreeNode* root,int & answer)
    {
        if (root==NULL)
            return 0;
        int left=find_maxPathSum(root->left,answer);
        int right=find_maxPathSum(root->right,answer);
        int without_root_root=root->val+left+right;
        int with_root_root=root->val+max(0,max(left,right));
        answer=max(answer,max(without_root_root,with_root_root));
        return with_root_root;
    }
};

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
    int sumNumbers(TreeNode* root) {
        if (root==NULL)
            return 0;
        int answer=0;    
        get_sumNumbers(root,answer,0);
        return answer;
    }
    void get_sumNumbers(TreeNode* root,int & answer,int num)
    {
        if (root->left==NULL && root->right==NULL)
        {
            answer=answer+root->val+num*10;
            return;
        }
        num=num*10+root->val;
        if (root->left!=NULL)
            get_sumNumbers(root->left,answer,num);
        if (root->right!=NULL)
            get_sumNumbers(root->right,answer,num);
    }
};

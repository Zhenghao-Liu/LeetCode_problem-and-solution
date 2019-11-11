//[关于字符串和数字转换](https://blog.csdn.net/sinat_40872274/article/details/81367815)
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
        else if (root->left==NULL && root->right==NULL)
            return root->val;
        int answer=0;    
        get_sumNumbers(root,answer,"");
        return answer;
    }
    void get_sumNumbers(TreeNode* root,int & answer,string num)
    {
        if (root->left==NULL && root->right==NULL)
        {
            answer=answer+root->val+stoi(num,0)*10;
            return;
        } 
        num=num+char(root->val+'0');
        if (root->left!=NULL)
            get_sumNumbers(root->left,answer,num);
        if (root->right!=NULL)
            get_sumNumbers(root->right,answer,num);
    }
};

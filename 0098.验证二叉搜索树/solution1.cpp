/*
* 中序遍历一次树，若不是所有[i]<[i+1]则不是二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        vector<int> LDR_answer(inorderTraversal(root));
        int LDR_answer_size=LDR_answer.size();
        for (int i=0;i<LDR_answer_size-1;++i)
            if (LDR_answer.at(i)>=LDR_answer.at(i+1))
                return false;
        return true;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root!=NULL)
            LDR_travel(answer,root);
        return answer;
    }
    void LDR_travel(vector<int>& answer,TreeNode* root)
    {
        if (root->left!=NULL)
            LDR_travel(answer,root->left);
        answer.push_back(int(root->val));
        if (root->right!=NULL)
            LDR_travel(answer,root->right);
    }
};

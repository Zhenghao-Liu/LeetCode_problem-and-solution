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
    void flatten(TreeNode* root) { 
        if (root==NULL)
            return;
        TreeNode * head=root;
        stack<TreeNode*> root_path;
        vector<int> answer;
        while (root!=NULL || !root_path.empty())
            if (root!=NULL)
            {
                answer.push_back(int(root->val));
                root_path.push(root);
                root=root->left;
            }
            else
            {
                root=root_path.top();
                root_path.pop();
                root=root->right;
            }
        int answer_size=answer.size();
        TreeNode * p=head;
        for (int i=1;i<answer_size;++i)
        {
            p->right=new TreeNode(answer.at(i));
            p->left=NULL;
            p=p->right;
        }
        p->left=NULL;
        p->right=NULL;
        root=head;
    }
};

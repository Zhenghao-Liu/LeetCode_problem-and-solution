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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==NULL)
            return {};
        vector<string> answer;
        get_ans(root,answer,{});
        return answer;
    }
    void get_ans(TreeNode * root,vector<string>& answer,vector<int> temp)
    {
        temp.push_back(root->val);
        if (root->left==NULL && root->right==NULL)
        {
            string s=to_string(temp.at(0));
            int size=temp.size();
            for (int i=1;i<size;++i)
                s=s+"->"+to_string(temp.at(i));
            answer.push_back(s);
            return;
        }
        if (root->left!=NULL)
            get_ans(root->left,answer,temp);
        if (root->right!=NULL)
            get_ans(root->right,answer,temp);
    }
};

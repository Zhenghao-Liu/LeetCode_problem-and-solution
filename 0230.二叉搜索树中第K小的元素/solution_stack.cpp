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
    int kthSmallest(TreeNode* root, int k) {
        int answer,index=0;
        stack<TreeNode*> s;
        while (root!=NULL || !s.empty())
            if (root!=NULL)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                answer=root->val;
                ++index;
                if (index==k)
                    return answer;
                root=root->right;
            }
        return answer;
    }
};

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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stack_roots;
        TreeNode* past_root;
        vector<TreeNode*> change_place;
        int left=INT_MIN,right,times=0;
        while(root!=NULL || !stack_roots.empty())
            if (root!=NULL)
            {
                stack_roots.push(root);
                root=root->left;
            }
            else
            {
                root=stack_roots.top();
                stack_roots.pop();
                right=root->val;
                if (left>right)
                {
                    change_place.push_back(past_root);
                    change_place.push_back(root);
                    ++times;
                    if (times==2)
                        break;
                }
                past_root=root;
                left=right;
                root=root->right;
            }
        swap(change_place.at(0)->val,change_place.back()->val);
    }
};

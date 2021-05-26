/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int x,y;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (helper(root)) {
            return false;
        }
        queue<TreeNode *> que;
        vector<TreeNode *> vec; 
        this->x=x;
        this->y=y;
        que.push(root);
        while (!que.empty()) {
            int sz=que.size();
            for (int i=0;i<sz;i++) {
                TreeNode *cur=que.front();
                que.pop();
                if (cur->left!=NULL) {
                    if (helper(cur->left)) {
                        vec.push_back(cur);
                    }
                    que.push(cur->left);
                }
                if (cur->right!=NULL) {
                    if (helper(cur->right)) {
                        vec.push_back(cur);
                    }
                    que.push(cur->right);
                }
            }
            if (vec.size()==2) {
                return vec.at(0)!=vec.at(1);
            } else if (vec.size()==1) {
                return false;
            }
        }
        return false;
    }
    bool helper(TreeNode * node) {
        return node->val==x || node->val==y;
    }
};
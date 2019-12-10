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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if (root==NULL)
            return {};
        queue<TreeNode*> queue_root;
        queue_root.push(root);
        int queue_root_size;
        TreeNode* p;
        while (!queue_root.empty())
        {
            queue_root_size=queue_root.size();
            for (int i=0;i<queue_root_size;++i)
            {
                p=queue_root.front();
                queue_root.pop();
                if (p->left!=NULL)
                    queue_root.push(p->left);
                if (p->right!=NULL)
                    queue_root.push(p->right);
            }
            answer.push_back(p->val);
        }
        return answer;
    }
};

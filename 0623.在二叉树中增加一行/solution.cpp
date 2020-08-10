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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1)
        {
            TreeNode * ans=new TreeNode(v);
            ans->left=root;
            return ans;
        }
        int depth=1;
        queue<TreeNode *>helper;
        helper.push(root);
        while (!helper.empty())
        {
            ++depth;
            int size=helper.size();
            if (depth==d)
            {
                for (int i=0;i<size;++i)
                {
                    TreeNode * parent=helper.front();
                    helper.pop();
                    TreeNode * left_child=parent->left;
                    TreeNode * right_child=parent->right;
                    parent->left=new TreeNode(v);
                    parent->right=new TreeNode(v);
                    parent->left->left=left_child;
                    parent->right->right=right_child;
                }
            }
            else
            {
                for (int i=0;i<size;++i)
                {
                    TreeNode *p=helper.front();
                    helper.pop();
                    if (p->left!=NULL)
                        helper.push(p->left);
                    if (p->right!=NULL)
                        helper.push(p->right);
                }
            }
        }
        return root;
    }
};

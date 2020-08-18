//中序遍历是个有序序列，之后双指针缩小范围即可
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        stack<TreeNode*> helper;
        TreeNode *p=root;
        while (!helper.empty() || p!=NULL)
        {
            if (p!=NULL)
            {
                helper.push(p);
                p=p->left;
            }
            else
            {
                p=helper.top();
                helper.pop();
                inorder.push_back(p->val);
                p=p->right;
            }
        }
        int l=0,r=(int)inorder.size()-1;
        while (l<r)
        {
            int sum=inorder.at(l)+inorder.at(r);
            if (sum==k)
                return true;
            else if (sum>k)
                --r;
            else
                ++l;
        }
        return false;
    }
};

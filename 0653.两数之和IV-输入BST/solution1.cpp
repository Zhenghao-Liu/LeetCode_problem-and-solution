//bst中序遍历是一个有序序列，之后用twosum方法即可
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
        unordered_set<int> num;
        for (int i:inorder)
        {
            if (num.find(k-i)!=num.end())
                return true;
            num.insert(i);
        }
        return false;
    }
};

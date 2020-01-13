/*
* 采用遍历方式然后通过哈希表给每一个节点映射一个父节点
* 在遍历找到p和q后开始对比两个节点的父节点
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stack_T;
        stack_T.push(root);
        unordered_map<TreeNode*,TreeNode*> father;
        //因为p或q可能为根节点，不加这个可能跳不出while
        father.insert({root,NULL});
        while (father.find(p)==father.end() || father.find(q)==father.end())
        {
            TreeNode *helper=stack_T.top();
            stack_T.pop();
            if (helper->right!=NULL)
            {
                father.insert({helper->right,helper});
                stack_T.push(helper->right);
            }
            if (helper->left!=NULL)
            {
                father.insert({helper->left,helper});
                stack_T.push(helper->left);
            }
        }
        //采用set优化查找效率
        unordered_set<TreeNode*> set_p_father;
        while (father.find(p)!=father.end())
        {
            //因为p可能为祖先，所以p这个节点也要存的
            set_p_father.insert(p);
            p=father.at(p);
        }
        while (set_p_father.find(q)==set_p_father.end())
            q=father.at(q);
        return q;
    }
};

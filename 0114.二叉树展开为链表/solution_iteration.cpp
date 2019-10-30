/*
* 可以把这颗二叉树假想为二叉搜索树
* 这样按照前序遍历的结果
* 最后的链表就是一个从根到叶有按从小到大顺序的链表
* 既然是二叉搜索树，左子节点一定小于右子节点，且左节点的最右节点为左节点中最大值
* 只需遍历找到左子节点的最右子节点，然后连接上右边即可
* 再重复操作即可
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
    void flatten(TreeNode* root) {
        TreeNode* index=root,*p;
        while (index!=NULL)
        {
            if (index->left!=NULL)
            {
                p=index->left;
                while (p->right!=NULL)
                    p=p->right;
                p->right=index->right;
                index->right=index->left;
                index->left=NULL;
            }
            index=index->right;
        }
    }
};

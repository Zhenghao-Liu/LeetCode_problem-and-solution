/**
* 二叉搜索树即中序遍历有序
* 删除值大于该节点，则表明要删除节点在右孩子
  删除值小于该节点，则表明要删除节点在左孩子
* 找到要删除的节点后，分类讨论该节点孩子情况
* 没有孩子，那么直接删除就可以了
* 只有左孩子，那就让左孩子顶替该节点
* 只有右孩子，那就让右孩子顶替该节点
* 同时有左孩子和右孩子，可以两种情况
  找左孩子中的最大值替换该节点
  找右孩子中的最小值替换该节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL)
            return NULL;
        if (key>root->val)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        if (key<root->val)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        //if (key==root->val)
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        if (root->right==NULL)
        {
            TreeNode * ans=root->left;
            delete root;
            return ans;
        }
        if (root->left==NULL)
        {
            TreeNode *ans=root->right;
            delete root;
            return ans;
        }
        //if (root->left!=NULL && root->right!=NULL)
        //采用找左孩子的最大值
        TreeNode * delete_p=root->left;
        while (delete_p->right!=NULL)
            delete_p=delete_p->right;
        swap(root->val,delete_p->val);
        root->left=deleteNode(root->left,key);
        return root;
    }
};

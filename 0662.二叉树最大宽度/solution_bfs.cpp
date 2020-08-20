//设满二叉树根节点标号为0，左孩子为2i，右孩子为2i+1，按行遍历，记录该行最左和最右的序号即可
//因为数据量问题，都用unsigned long long
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
typedef pair<TreeNode *,unsigned long long> pii;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root==NULL)
            return 0;
        queue<pii>helper;
        helper.push({root,0});
        unsigned long long ans=0;
        while (!helper.empty())
        {
            int size=helper.size();
            unsigned long long start,end;
            for (int i=0;i<size;++i)
            {
                auto [node,index]=helper.front();
                helper.pop();
                if (node->left!=NULL)
                    helper.push({node->left,index*2});
                if (node->right!=NULL)
                    helper.push({node->right,index*2+1});
                if (i==0)
                    start=index;
                if (i==size-1)
                    end=index;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};

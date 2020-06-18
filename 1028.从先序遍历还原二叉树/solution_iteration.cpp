/*
* 因为本题特殊性：如果节点只有一个子节点，那么保证该子节点为左子节点
* 所以一个节点对于上一个节点只有两种可能
  1. 是上一个节点的左孩子
  2. 是上上上···上个节点的右孩子
* 采用栈的大小来代表深度，然后用前序遍历方式模拟即可
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
    TreeNode* recoverFromPreorder(string S) {
        int S_size=S.size();
        if (S.empty())
            return NULL;
        int index=0;
        stack<TreeNode *> helper;
        while (index<S_size)
        {
            int start=index;
            while (index<S_size && S.at(index)=='-')
                ++index;
            int depth=index-start;
            start=index;
            while (index<S_size && S.at(index)>='0' && S.at(index)<='9')
                ++index;
            TreeNode *p=new TreeNode(stoi(S.substr(start,index)));
            if (depth==helper.size())
            {
                if (!helper.empty())
                    helper.top()->left=p;
            }
            else
            {
                while (!helper.empty() && depth!=helper.size())
                    helper.pop();
                helper.top()->right=p;
            }
            helper.push(p);
        }
        while (helper.size()>1)
            helper.pop();
        return helper.top();
    }
};

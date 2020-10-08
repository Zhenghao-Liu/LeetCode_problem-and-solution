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
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int level=-1;
        q.push(root);
        vector<int> vec;
        while (!q.empty())
        {
            int size=q.size();
            vec.clear();
            ++level;
            for (int i=0;i<size;++i)
            {
                vec.push_back(q.front()->val);
                TreeNode * t=q.front();
                q.pop();
                if (t->left!=NULL)
                    q.push(t->left);
                if (t->right!=NULL)
                    q.push(t->right);
            }
            if (level%2==0)
            {
                if (vec.at(0)%2==0)
                    return false;
                for (int j=1;j<vec.size();++j)
                    if (vec.at(j)%2==0 || vec.at(j)<=vec.at(j-1))
                        return false;
            }
            else
            {
                if (vec.at(0)%2==1)
                    return false;
                for (int j=1;j<vec.size();++j)
                    if (vec.at(j)%2==1 || vec.at(j)>=vec.at(j-1))
                        return false;
            }
        }
        return true;
    }
};

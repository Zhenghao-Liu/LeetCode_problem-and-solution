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
    vector<int> vec1,vec2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vec1.clear();
        vec2.clear();
        dfs(root1,false);
        dfs(root2,true);
        int sz1=vec1.size(),sz2=vec2.size();
        int i=0,j=0;
        while (i<sz1 && j<sz2) {
            if (vec1.at(i)!=vec2.at(j)) {
                break;
            }
            i++;
            j++;
        }
        return i==sz1 && j==sz2;
    }
    void dfs(TreeNode *node,bool sec) {
        if (node==NULL) {
            return;
        }
        dfs(node->left,sec);
        if (node->left==NULL && node->right==NULL) {
            if (!sec) {
                vec1.push_back(node->val);
            } else {
                vec2.push_back(node->val);
            }
        }
        dfs(node->right,sec);
    }
};
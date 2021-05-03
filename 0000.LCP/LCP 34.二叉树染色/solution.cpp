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
    int k;
public:
    int maxValue(TreeNode* root, int k) {
        if (root==NULL) {
            return 0;
        }
        this->k=k;
        vector<int> v=dfs(root);
        return *max_element(v.begin(),v.end());
    }
    vector<int> dfs(TreeNode *root) {
        vector<int> v(k+1,0);
        if (root==NULL) {
            return v;
        }
        vector<int> l=dfs(root->left),r=dfs(root->right);
        int lmx=*max_element(l.begin(),l.end()),rmx=*max_element(r.begin(),r.end());
        v.at(0)=lmx+rmx;
        for (int i=1;i<=k;i++) {
            int a=0;
            for (int j=0;j<i;j++) {
                a=max(a,l.at(j)+r.at(i-1-j));
            }
            v.at(i)=root->val+a;
        }
        return v;
    }
};
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
struct node{
    int val,x,y;
};
class Solution {
    vector<node> vec;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vec.clear();
        dfs(root,0,0);
        sort(vec.begin(),vec.end(),[](const node & A,const node & B){
            return (A.y<B.y) ||
                (A.y==B.y && A.x<B.x) ||
                (A.y==B.y && A.x==B.x && A.val<B.val);
        });
        vector<vector<int>> ans;
        int lst=INT_MIN/2;
        for (node &i:vec) {
            int val=i.val,y=i.y;
            if (y!=lst) {
                ans.push_back({});
            }
            lst=y;
            ans.back().push_back(val);
        }
        return ans;
    }
    void dfs(TreeNode *root,int x,int y) {
        if (root==NULL) {
            return;
        }
        vec.push_back({root->val,x,y});
        if (root->left!=NULL) {
            dfs(root->left,x+1,y-1);
        }
        if (root->right!=NULL) {
            dfs(root->right,x+1,y+1);
        }
    }
};
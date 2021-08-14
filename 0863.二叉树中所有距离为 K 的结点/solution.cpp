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
    unordered_map<int,vector<int>> ump;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ump.clear();
        dfsp(root,NULL);
        int step=0;
        queue<int> que;
        que.push(target->val);
        unordered_set<int> ust;
        ust.insert(target->val);
        while (step<k && !que.empty()) {
            int sz=que.size();
            step++;
            for (int i=0;i<sz;i++) {
                int cur=que.front();
                que.pop();
                for (int nxt:ump[cur]) {
                    if (ust.find(nxt)!=ust.end()) {
                        continue;
                    }
                    ust.insert(nxt);
                    que.push(nxt);
                }
            }
        }
        vector<int> ans;
        ans.reserve(que.size());
        while (!que.empty()) {
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
    void dfsp(TreeNode *root,TreeNode *par) {
        if (par!=NULL) {
            ump[root->val].push_back(par->val); 
        }
        if (root->left!=NULL) {
            ump[root->val].push_back(root->left->val);
            dfsp(root->left,root);
        }
        if (root->right!=NULL) {
            ump[root->val].push_back(root->right->val);
            dfsp(root->right,root);
        }
    }
};
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
    vector<vector<int>> m;
    vector<int> temp;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        m.clear();
        temp.clear();
        dfs(root);
        int ans=0;
        for (vector<int> &i:m)
        {
            
            sort(i.begin(),i.end());
            //for (int &j:i)
            //    cout << j << ' ';
            //cout << endl;
            bool judge_single=false;
            int size=i.size();
            bool judge=true;
            for (int j=0;j<size;++j)
            {
                int count=1;
                while (j+1<size && i.at(j)==i.at(j+1))
                {
                    ++j;
                    ++count;
                }
                if (count%2==0)
                    continue;
                else if (!judge_single)
                    judge_single=true;
                else
                {
                    judge=false;
                    break;
                }
            }
            if (judge)
                ++ans;
        }
        //cout << endl;
        return ans;
    }
    void dfs(TreeNode* root)
    {
        if (root==NULL)
            return;
        temp.push_back(root->val);
        if (root->left==NULL && root->right==NULL)
            m.push_back(temp);
        dfs(root->left);
        dfs(root->right);
        temp.pop_back();
    }
};

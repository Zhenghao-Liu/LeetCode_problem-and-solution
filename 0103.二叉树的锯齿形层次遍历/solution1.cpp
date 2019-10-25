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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> queue_root;
        if (root!=NULL)
            queue_root.push(root);
        vector<vector<int>> answer;
        int index=-1,loop_times;
        TreeNode* p;
        while (!queue_root.empty())
        {
            answer.push_back({});
            ++index;
            loop_times=queue_root.size();
            for (int i=0;i<loop_times;++i)
            {
                p=queue_root.front();
                answer.at(index).push_back(int(p->val));
                if (p->left!=NULL)
                    queue_root.push(p->left);
                if (p->right!=NULL)
                    queue_root.push(p->right);
                queue_root.pop();
            }
        }
        int answer_size=answer.size();
        for (int i=1;i<answer_size;i=i+2)
            reverse(answer.at(i).begin(),answer.at(i).end());
        return answer;
    }
};

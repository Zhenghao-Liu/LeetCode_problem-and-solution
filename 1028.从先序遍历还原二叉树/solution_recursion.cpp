//纪录深度
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
        return dfs(S,index,S_size,0);
    }
    TreeNode * dfs(string &S,int &index,const int &S_size,int depth)
    {
        int start=index;
        while (index<S_size && S.at(index)>='0' && S.at(index)<='9')
            ++index;
        TreeNode *p=new TreeNode(stoi(S.substr(start,index-start)));
        start=index;
        while (index<S_size && S.at(index)=='-')
            ++index;
        if (index-start==depth+1)
            p->left=dfs(S,index,S_size,depth+1);
        else
        {
            index=start;
            return p;
        }
        start=index;
        while (index<S_size && S.at(index)=='-')
            ++index;
        if (index-start==depth+1)
            p->right=dfs(S,index,S_size,depth+1);
        else
        {
            index=start;
            return p;
        }
        return p;
    }
};

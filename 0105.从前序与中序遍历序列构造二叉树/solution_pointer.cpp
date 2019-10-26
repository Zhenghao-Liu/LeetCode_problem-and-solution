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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int preorder_size=preorder.size();
	if (preorder_size==0)
		return NULL;
    int * preorder_m=new int[preorder_size];
    int * inorder_m=new int[preorder_size];
    for (int i=0;i<preorder_size;++i)
    {
        preorder_m[i]=preorder.at(i);
        inorder_m[i]=inorder.at(i);
    }
    TreeNode* root=to_buildTree(preorder_m,preorder_m+preorder_size-1,inorder_m,inorder_m+preorder_size-1);
    delete []preorder_m;
    delete []inorder_m;
    return root;
}
    TreeNode* to_buildTree(int* preorder_begin,int* preorder_end,int* inorder_begin,int* inorder_end)
    {
        if (preorder_end<preorder_begin)
            return NULL;
        TreeNode* root=new TreeNode(*preorder_begin);
	    if (preorder_end==preorder_begin)
	    {
		    root->left=NULL;
		    root->right=NULL;
		    return root;
	    }
        int *index=inorder_begin;
        while (index<=inorder_end)
            if (*index==*preorder_begin)
                break;
            else
                ++index;
        root->left=to_buildTree(preorder_begin+1,preorder_begin+(index-inorder_begin),inorder_begin,index-1);
        root->right=to_buildTree(preorder_begin+(index-inorder_begin)+1,preorder_end,index+1,inorder_end);
        return root;
    }
};

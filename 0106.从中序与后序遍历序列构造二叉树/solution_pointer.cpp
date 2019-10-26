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
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	int inorder_size=inorder.size();
	if (inorder_size==0)
		return NULL;
    int * inorder_m=new int[inorder_size];
    int * postorder_m=new int[inorder_size];
    for (int i=0;i<inorder_size;++i)
    {
        inorder_m[i]=inorder.at(i);
        postorder_m[i]=postorder.at(i);
    }
    TreeNode* root=to_buildTree(inorder_m,inorder_m+inorder_size-1,postorder_m,postorder_m+inorder_size-1);
    delete []inorder_m;
    delete []postorder_m;
    return root;
}
    TreeNode* to_buildTree(int* inorder_begin,int* inorder_end,int* postorder_begin,int* postorder_end)
    {
        if (inorder_end<inorder_begin)
            return NULL;
        TreeNode* root=new TreeNode(*postorder_end);
	    if (inorder_end==inorder_begin)
	    {
		    root->left=NULL;
		    root->right=NULL;
		    return root;
	    }
        int *index=inorder_begin;
        while (index<=inorder_end)
            if (*index==*postorder_end)
                break;
            else
                ++index;
        root->left=to_buildTree(inorder_begin,index-1,postorder_begin,postorder_begin+(index-inorder_begin)-1);
        root->right=to_buildTree(index+1,inorder_end,postorder_begin+(index-inorder_begin),postorder_end-1);
        return root;
    }
};

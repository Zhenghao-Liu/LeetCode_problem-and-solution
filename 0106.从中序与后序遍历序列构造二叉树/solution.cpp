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
	    TreeNode* root=new TreeNode(postorder.back());
	    if (inorder_size==1)
	    {
		    root->left=NULL;
		    root->right=NULL;
		    return root;
	    }
	    int index(find(inorder.begin(),inorder.end(),postorder.back())-inorder.begin());
	    vector<int> left_inorder(inorder.begin(),inorder.begin()+index);
        vector<int> left_postorder(postorder.begin(),postorder.begin()+index);
	    vector<int> right_inorder(inorder.begin()+index+1,inorder.end());
        vector<int> right_postorder(postorder.begin()+index,postorder.end()-1);
	    root->left=buildTree(left_inorder,left_postorder);
	    root->right=buildTree(right_inorder,right_postorder);
	    return root; 
    }
};

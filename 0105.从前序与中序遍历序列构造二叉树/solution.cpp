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
	TreeNode* root=new TreeNode(preorder.at(0));
	if (preorder_size==1)
	{
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	int index(find(inorder.begin(),inorder.end(),preorder.at(0))-inorder.begin());
	vector<int> left_preorder(preorder.begin()+1,preorder.begin()+index+1);
	vector<int> right_preorder(preorder.begin()+index+1,preorder.end());
	vector<int> left_inorder(inorder.begin(),inorder.begin()+index);
	vector<int> right_inorder(inorder.begin()+index+1,inorder.end());
	root->left=buildTree(left_preorder,left_inorder);
	root->right=buildTree(right_preorder,right_inorder);
	return root;
}
};

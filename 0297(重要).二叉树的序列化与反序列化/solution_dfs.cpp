//巧用stringstream
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL)
            return "!";
        return to_string(root->val)+' '+serialize(root->left)+' '+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="!")
            return NULL;
        stringstream ss(data);
        TreeNode * root=NULL;
        helper(root,ss);
        return root;
    }

    void helper(TreeNode* & p,stringstream & ss)
    {
        string s;
        ss >> s;
        if (s=="!")
            return;
        p=new TreeNode(stoi(s));
        helper(p->left,ss);
        helper(p->right,ss);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

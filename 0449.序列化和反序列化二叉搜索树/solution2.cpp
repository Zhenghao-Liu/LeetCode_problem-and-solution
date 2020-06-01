//二叉搜索树，那么中序遍历是个有序序列，通过前序遍历，然后在排序得到中序遍历，借用105.从前序与中序遍历序列构造二叉树，就可以建树了
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
            return "";
        string data;
        stack<TreeNode *> helper;
        TreeNode *p=root;
        while (!helper.empty() || p!=NULL)
        {
            if (p!=NULL)
            {
                data+=to_string(p->val)+' ';
                helper.push(p);
                p=p->left;
            }
            else
            {
                p=helper.top();
                helper.pop();
                p=p->right;
            }
        }
        data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        vector<int> preorder;
        stringstream ss;
        ss << data;
        string temp;
        while (ss >> temp)
            preorder.push_back(stoi(temp));
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

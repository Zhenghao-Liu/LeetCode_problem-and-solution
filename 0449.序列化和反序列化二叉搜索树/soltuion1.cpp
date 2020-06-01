//没有利用到二叉搜索树，按照LC的输入拉序列化反序列化所有的二叉树
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
        vector<string> v_ans;
        queue<TreeNode*> helper;
        helper.push(root);
        while (!helper.empty())
        {
            TreeNode *p=helper.front();
            helper.pop();
            if (p!=NULL)
            {
                v_ans.push_back(to_string(p->val));
                helper.push(p->left);
                helper.push(p->right);
            }
            //else if (p==NULL)
            else
            {
                v_ans.push_back("null");
            }
        }
        //弹出末尾的null，且注意root本身就是null的特殊情况
        while (v_ans.size()>1 && v_ans.back()=="null")
            v_ans.pop_back();
        string ans;
        for (string &i:v_ans)
            ans+=i+',';
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v_data;
        int data_size=data.size();
        string letter;
        for (int i=0;i<=data_size;++i)
        {
            if (i==data_size || data.at(i)==',')
            {
                v_data.push_back(letter);
                letter.clear();
            }
            else
                letter+=data.at(i);
        }
        if (v_data.at(0)=="null")
            return NULL;
        int v_data_size=v_data.size();
        TreeNode * root=new TreeNode(stoi(v_data.at(0)));
        queue<TreeNode *> helper;
        helper.push(root);
        helper.push(root);
        int index=1;
        bool left_child=true;
        while (index<v_data_size)
        {
            TreeNode * p=helper.front();
            helper.pop();
            if (left_child)
            {
                if (v_data.at(index)!="null")
                {
                    p->left=new TreeNode(stoi(v_data.at(index)));
                    helper.push(p->left);
                    helper.push(p->left);
                }
            }
            else
            {
                if (v_data.at(index)!="null")
                {
                    p->right=new TreeNode(stoi(v_data.at(index)));
                    helper.push(p->right);
                    helper.push(p->right);
                }
            }
            ++index;
            left_child=!left_child;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

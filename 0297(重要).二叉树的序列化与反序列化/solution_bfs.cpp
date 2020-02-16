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
        stringstream ss;
        queue<TreeNode*> queue_root;
        queue_root.push(root);
        TreeNode *p;
        while (!queue_root.empty())
        {
            int loop_times=queue_root.size();
            bool next_line=false;
            for (int i=0;i<loop_times;++i)
            {
                p=queue_root.front();
                queue_root.pop();
                if (p!=NULL)
                {
                    ss << to_string(p->val) << '+';
                    if (!next_line && (p->left!=NULL || p->right!=NULL))
                        next_line=true;
                    queue_root.push(p->left);
                    queue_root.push(p->right);
                }
                else
                    ss << "!+";
            }
            if (!next_line)
                break;
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int data_size=data.size();
        if (data_size==0)
            return NULL;
        int index=0,num=0;
        int judge_plus_minus=1;
        if (data.at(0)=='-')
        {
            ++index;
            judge_plus_minus=-1;
        }
        for (;index<data_size && data.at(index)>='0';++index)
            num=num*10-'0'+data.at(index);
        num*=judge_plus_minus;
        TreeNode * root=new TreeNode(num);
        queue<TreeNode*> queue_root;
        queue_root.push(root);
        TreeNode * p;
        num=0;
        ++index;
        int judge_left=1;
        judge_plus_minus=1;
        for (;index<data_size;++index)
        {
            if (data.at(index)>='0')
                num=num*10-'0'+data.at(index);
            else if (data.at(index)=='-')
                judge_plus_minus=-1;
            else if (data.at(index)=='!')
                num=5201314;
            else
            {
                num*=judge_plus_minus;
                p=queue_root.front();
                if (judge_left)
                {
                    if (num!=5201314)
                        p->left=new TreeNode(num);
                    if (p->left!=NULL)
                        queue_root.push(p->left);
                }
                else
                {
                    if (num!=5201314)
                        p->right=new TreeNode(num);
                    queue_root.pop();
                    if (p->right!=NULL)
                        queue_root.push(p->right);
                }
                num=0;
                judge_left^=1;
                judge_plus_minus=1;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

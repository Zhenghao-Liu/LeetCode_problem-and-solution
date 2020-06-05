#ifndef TREE_TO_STRING
#define TREE_TO_STRING

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree_String {
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

class show_tree {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return answer;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack_roots;
        vector<int> answer;
        while(root!=NULL || !stack_roots.empty())
            if (root!=NULL)
            {
                stack_roots.push(root);
                root=root->left;
            }
            else
            {
                root=stack_roots.top();
                stack_roots.pop();
                answer.push_back(int(root->val));
                root=root->right;
            }
        return answer;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> root_path;
        vector<int> answer({});
        while (root!=NULL || !root_path.empty())
            if (root!=NULL)
            {
                answer.push_back(int(root->val));
                root_path.push(root);
                root=root->left;
            }
            else
            {
                root=root_path.top();
                root_path.pop();
                root=root->right;
            }
        return answer;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> root_path;
        TreeNode* past=NULL;
        while (root!=NULL || !root_path.empty())
            if (root!=NULL)
            {
                root_path.push(root);
                root=root->left;
            }
            else
            {
                root=root_path.top();
                if (root->right==NULL || root->right==past)
                {
                    answer.push_back(root->val);
                    root_path.pop();
                    past=root;
                    root=NULL;
                }
                else
                    root=root->right;
            }
        return answer;
    }
};
#endif
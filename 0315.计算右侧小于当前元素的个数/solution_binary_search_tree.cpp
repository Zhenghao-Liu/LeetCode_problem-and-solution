//借用二叉搜索树有序特性
class Solution {
private:
struct TreeNode{
    int val;
    int left_child_num;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), left_child_num(0) {}
 };
public:
    vector<int> countSmaller(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> count(nums_size,0);
        TreeNode * root=new TreeNode(nums.back());
        for (int i=nums_size-2;i>=0;--i)
        {
            int less_than_new=0;
            helper(root,new TreeNode(nums.at(i)),less_than_new);
            count.at(i)=less_than_new;
        }
        return count;
    }
    void helper(TreeNode *node,TreeNode * new_node,int & less_than_new)
    {
        if (new_node->val > node->val)
        {
            less_than_new+=node->left_child_num+1;
            if (node->right==NULL)
                node->right=new_node;
            else
                helper(node->right,new_node,less_than_new);
        }
        //等于的情况也插在左孩子
        else
        {
            ++node->left_child_num;
            if (node->left==NULL)
                node->left=new_node;
            else
                helper(node->left,new_node,less_than_new);
        }
    }
};

/*
* 我们用dfs方式遍历二叉树，并用栈存储节点
* 当遇到节点为'#'时，我们检测栈是否超过两个节点，并且栈顶为'#'，意思是当前子树已经遍历完了，那么就可以用一个'#'来代替这颗子树
* 而新的'#'又可以像递归一样，去构成一颗新的完整子树，又可以生成新的'#'继续递归下去
* 如果是正确的前序序列，那么这颗二叉树已经遍历完了，所以最后只剩下用'#'代替这颗二叉树
* 如果此时栈已经只剩下一个'#'了，即剩下节点都是多余的节点，返回false
* 最后判断下是否是一个'#'即整颗二叉树遍历完即可
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> helper;
        int preorder_size=preorder.size();
        for (int i=0;i<preorder_size;)
        {
            if (preorder.at(i)==',')
            {
                ++i;
                continue;
            }
            if (helper.size()==1 && helper.top()=='#')
                return false;
            string temp;
            while (i<preorder_size && preorder.at(i)!=',')
            {
                temp+=preorder.at(i);
                ++i;
            }
            if (temp!="#")
                helper.push('n');
            else
            {
                while (helper.size()>=2 && helper.top()=='#')
                {
                    helper.pop();
                    helper.pop();
                }
                helper.push('#');
            }
        }
        return helper.size()==1 && helper.top()=='#';
    }
};

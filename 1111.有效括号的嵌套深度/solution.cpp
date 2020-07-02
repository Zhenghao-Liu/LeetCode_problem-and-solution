//保证栈内一半的括号属于序列 A，一半的括号属于序列 B
//那么就能保证拆分后最大的嵌套深度最小，是当前最大嵌套深度的一半。要实现这样的对半分配，把奇数层的 ( 分配给 A，偶数层的 ( 分配给 B 即可
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        ans.reserve(seq.size());
        int depth=0;
        for (char &i:seq)
            if (i=='(')
            {
                ans.push_back(depth%2);
                ++depth;
            }
            else
            {
                --depth;
                ans.push_back(depth%2);
            }
        return ans;
    }
};

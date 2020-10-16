/*
 * 可以把1当成是左括号'('，0当成是右括号')'
 * 0 和 1 的数量相等。 → “右括号” 数量和 “左括号” 相同。
   二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。→ “右括号” 必须能够找到一个 “左括号” 匹配。
 * 首先选择 S 的两个 连续 且非空的 特殊 的子串，然后将它们交换。
   翻译过来就是：选择 S 中的两个 相邻 的 有效的括号字符串，然后交换即可
 * 一个有效括号字符串，内部还是有效的括号字符串，所以先递归去解决内部的有效括号字符串
 * 然后再去解决同层的有效括号字符串
 */
class Solution {
public:
    string makeLargestSpecial(string S) {
        if (S.empty())
            return "";
        int S_size=S.size();
        int cnt=0;
        int i=0;
        vector<string> vec;
        for (int j=0;j<S_size;++j)
        {
            cnt+= S.at(j)=='1' ? 1 : -1;
            if (cnt==0)
            {
                //[i+1]~[j-1]
                vec.push_back("1"+makeLargestSpecial(S.substr(i+1,j-1-i))+"0");
                i=j+1;
            }
        }
        sort(vec.begin(),vec.end(),[](const string &A,const string &B){
            return A+B>B+A;
        });
        string ans;
        for (string &s:vec)
            ans+=s;
        return ans;
    }
};

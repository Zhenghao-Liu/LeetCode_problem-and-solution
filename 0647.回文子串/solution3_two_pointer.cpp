/*
* 一个长度为n的字符串s，要想构造回文子串，那么它作为回文子串可能的对称轴有2*n-1个位置
  1. 以每个字符为对称轴，即n中可能
  2. 以两个字符中间的位置作为对称轴，即n-1种可能
* 枚举这两种情况的所有对称轴，然后双指针方式从中心往两端拓展即可
*/
class Solution {
public:
    int countSubstrings(string s) {
        int s_size=s.size();
        int ans=0;
        for (int i=0;i<s_size;++i)
        {
            int left=i,right=i;
            while (left>=0 && right<s_size && s.at(left)==s.at(right))
            {
                ++ans;
                --left;
                ++right;
            }
        }
        for (int i=1;i<s_size;++i)
        {
            int left=i-1,right=i;
            while (left>=0 && right<s_size && s.at(left)==s.at(right))
            {
                ++ans;
                --left;
                ++right;
            }
        }
        return ans;
    }
};

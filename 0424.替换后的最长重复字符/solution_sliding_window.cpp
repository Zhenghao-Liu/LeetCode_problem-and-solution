/*
* 退化到k=0的情况就是s中最长连续子序列
  用滑动窗口来做[left,right]
  right-left+1来保证了滑窗的长度
* 现在k>0其实就是滑窗中允许有k个错误后，最长连续子序列
* 所以要统计滑窗中某个字母出现最多的次数，因为它能构成滑窗中在错误k次后最长的子序列
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left=0,right=0;
        int s_size=s.size();
        int letter_max_appear_times=0;
        for (;right<s_size;++right)
        {
            int index=s.at(right)-'A';
            ++count.at(index);
            letter_max_appear_times=max(letter_max_appear_times,count.at(index));
            if (right-left+1>letter_max_appear_times+k)
            {
                --count.at(s.at(left)-'A');
                ++left;
            }
        }
        return s_size-left;
    }
};

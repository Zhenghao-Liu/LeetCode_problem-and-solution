/*
* [KMP字符串匹配算法1](https://www.bilibili.com/video/av11866460)
* [KMP字符串匹配算法2](https://www.bilibili.com/video/av16828557)
* 我们拿aacd这个例子
* 答案是dcaacd
* 构建最短回文串我们可以构建一个反过来的s即r_s与s去匹配
* s="aacd";r_s="dcaa"
* 我们假设二者相加，中间加一个标记符来区分两个字符串
* 新s="aacd$dcaa"
* 我们发现，通过求他们的最长公共前后缀就能求最短回文串
* 最长公共前后缀为2即"aa"
* 所以就想到了用KMP算法中求prefix_table的想法来求最长公共前后缀
* 最后再叠加起(r_s除去最长公共前后缀剩下一部分)和(最初的s)即为最短回文串
* 即"dc"+"aacd"
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        int s_size=s.size();
        if (s_size<2)
            return s;
        string r_s=s,original_s=s;
        reverse(r_s.begin(),r_s.end());
        s=s+'$'+r_s;
        s_size=s.size();
        vector<int> prefix_table(s_size);
        int len=0;
        prefix_table.at(0)=0;
        if (s.at(0)==s.at(1))
        {
            prefix_table.at(1)=1;
            ++len;
        }
        else
            prefix_table.at(0)=0;
        for (int i=2;i<s_size;)
            if (s.at(i)==s.at(len))
            {
                prefix_table.at(i)=len+1;
                ++len;
                ++i;
            }
            else
            {
                if (len>0)
                    len=prefix_table.at(len-1);
                else
                {
                    len=0;
                    prefix_table.at(i)=0;
                    ++i;
                }
            }
        string temp=string(r_s.begin(),r_s.end()-prefix_table.at(s_size-1));
        return temp+original_s;
    }
};

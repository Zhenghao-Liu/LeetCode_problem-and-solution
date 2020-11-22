/*
 * 操作1：交换字符位置
   操作2：将现有两种字符互换
 * 贪心：两个字符串的字符集要相同，其次，按出现频次排序后，要相等，之后通过操作1一定能变到一样
 */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        if (size1!=size2)
            return false;
        int cnt1[26]={0};
        int cnt2[26]={0};
        for (char i:word1)
            ++cnt1[i-'a'];
        for (char i:word2)
            ++cnt2[i-'a'];
        for (int i=0;i<26;++i)
            if ((cnt1[i]!=0 && cnt2[i]!=0) || (cnt1[i]==0 && cnt2[i]==0))
                continue;
            else
                return false;
        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        for (int i=0;i<26;++i)
            if (cnt1[i]!=cnt2[i])
                return false;
        return true;
    }
};

/*
* 既然是出现偶数次，那我们只用0表示偶，1表示奇就好了
* 那就会用到异或
* 对于aeiou，可以用一个5位的2进制数表示，即00000~11111
* 通过前缀和来表示当前以[i]结尾的序列的元音奇偶情况，这里用cur表示
* 偶数-偶数=偶数 奇数-奇数=偶数
* 即通过前缀和即[j]-[i]这种情况求是否是元音出现了偶数
  我们又采用了二进制来存
  那么就只有上面两种情况
  压缩成二进制就只有一种情况：就是相等，因为要想相减结果为偶数即二进制下0，只有1-1=0-0=0
* 又因为最长，所以我们遇到一种情况只需要记录在s中最左边出现的情况，即记录一次就可以了，让右-左，左尽可能小
* 又因为一共用了5位2进制数表示，所以最多只可能2^5可能，用prefix存，i表示奇偶的情况，[i]表示出现在s奇偶情况为i的最左边的位置
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans=0;
        int s_size=s.size();
        vector<int> prefix(pow(2,5),-1);
        prefix.at(0)=0;
        int cur=0;
        for (int i=0;i<s_size;++i)
        {
            if (s.at(i)=='a')
                cur^=(1<<0);
            else if (s.at(i)=='e')
                cur^=(1<<1);
            else if (s.at(i)=='i')
                cur^=(1<<2);
            else if (s.at(i)=='o')
                cur^=(1<<3);
            else if (s.at(i)=='u')
                cur^=(1<<4);
            if (prefix.at(cur)!=-1)
                ans=max(ans,i+1-prefix.at(cur));
            else
                prefix.at(cur)=i+1;
        }
        return ans;
    }
};

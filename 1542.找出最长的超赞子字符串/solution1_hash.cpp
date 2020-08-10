/*
* 能经过任意次交换后能够变为回文字符串，即这个字符串里面的字符出现次数要么为偶数，要么为奇数，且该奇数次的字符个数只能为1
* 既然不是滑窗自然就想到前缀和方式统计奇偶，就是类似于twosum的方法，边求前缀和，边在哈希表找对应的位置
* 但是涉及10个数字，复杂度过高，且只用统计奇偶，就想到了用1来代表奇数情况，0代表偶数情况
* 那么要压缩复杂度自然就想到了状压：把0~9共10个数压缩到一个int的低10位，二进制下1代表奇数，0代表偶数情况
* 那么对于状压后的前缀和就不再是相减
* 设当前状态是i，需要在哈希表找到j，j要满足j^i=res，这个res要满足在二进制下1只能最多出现一次
* 那么找可能的j分两种情况
  1. i本身就满足，因为自身与自身异或一定是0，即i^i=0满足要求
  2. i的某一位与1异或，那么异或后的该位将取反，那么i^j=是一个刚刚变换位是1其他位均为0的数
* 解题步骤
  1. 用哈希表存取状压状态出现的第一次位置，因为题目要求最长
  2. 记录当下的状态压缩i，找哈希表中的j，求得长度
*/
class Solution {
public:
    int longestAwesome(string s) {
        int s_size=s.size();
        unordered_map<int,int> pos;
        pos[0]=-1;
        int sum=0;
        int ans=0;
        for (int i=0;i<s_size;++i)
        {
            int a=1<<(s.at(i)-'0');
            sum^=a;
            if (pos.find(sum)!=pos.end())
                ans=max(ans,i-pos.at(sum));
            for (int ii=0;ii<10;++ii)
            {
                int j=sum^(1<<ii);
                if (pos.find(j)!=pos.end())
                    ans=max(ans,i-pos.at(j));
            }
            if (pos.find(sum)==pos.end())
                pos[sum]=i;
        }
        return ans;
    }
};

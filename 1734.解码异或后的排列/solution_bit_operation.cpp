/*
 * 因为是小于等于n的数，且不会重复，即所有数字在[1,n]中且不重复
 * 设n=5
   则perm=[a,b,c,d,e]
       enco=[f,g,h,i]
   因为n确定，所以可以知道所有数的异或结果
   即a^b^c^d^e的结果是知道的
 * 我们知道的是enco的值，只需要找到perm的随意一个位置的值就可以构造答案
 * 可以发现
   f=a^b
   g=b^c
   h=c^d
   i=d^e
 * 现在知道a^b^c^d^e，可以用g=b^c和i=d^e去消除，只剩下一个a，这样perm就构造出来一个元素，即答案
 */
class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int size=enc.size();
        int n=size+1;
        int a=0;
        for (int i=1;i<=n;i++) {
            a^=i;
        }
        for (int i=size-1;i>=0;i-=2) {
            a^=enc.at(i);
        }
        vector<int> ans(n);
        ans.at(0)=a;
        for (int i=0;i<size;i++) {
            ans.at(i+1)=ans.at(i)^enc.at(i);
        }
        return ans;
    }
};

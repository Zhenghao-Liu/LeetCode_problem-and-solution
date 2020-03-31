/*
* 对于奇数i即二进制下最右边一位为1，那么他也就比i-1多了最右边的那个1而已
* 对于偶数i即二进制下最右边一位为0，即有无这个0都无影响，那么将i右移一位，即是答案
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for (int i=1;i<=num;++i)
            //奇数
            if (i&1==1)
                ans.at(i)=ans.at(i-1)+1;
            //偶数
            else
                ans.at(i)=ans.at(i>>1);
        return ans;
    }
};

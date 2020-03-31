/*
* 十进制   二进制    1的个数
* 0   0   0
  1   1   1
  
  2   10   1
  3   11   2
  
  4   100   1
  5   101   2
  6   110   2
  7   111   3
* 按2的幂次分成组，每一组都是上面所有元素对应再在二进制下最左边加上了一个1
*/
class Solution {
public:
    vector<int> countBits(int num) {
        if (num==0)
            return {0};
        if (num==1)
            return {0,1};
        vector<int> ans(num+1,0);
        ans.at(0)=0;
        ans.at(1)=1;
        int end_limit=2;
        for (int i=2;i<=num;)
        {
            int index=0;
            end_limit<<=1;
            while (i<=num && i<end_limit)
            {
                ans.at(i)=ans.at(index)+1;
                ++index;
                ++i;
            }
        }
        return ans;
    }
};

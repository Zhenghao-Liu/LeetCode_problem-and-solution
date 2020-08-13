/*
* 1. a^b^c^d正确序列
* 2. b^b^c^d数据错误后的序列
* 式子1异或式子2后能够得到a^b
  即lost_num^repeat_num
* 怎么区分开来呢？先用lowbit区分开来lost_num和repeat_num不同位中的最低位
  因为不同数异或为1，同数异或为0，lowbit求最低位的1
* 再根据该位分成两组，再求式子1、式子2、式子1异或式子2的值即可求出a、b
* 倘若数组错误后的序列中出现了a，那说明a是repeat_num，出现b则b是repeat_num
* 
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int nums_size=nums.size();
        int A=0;
        for (int i=1;i<=nums_size;++i)
            A^=i;
        for (int i=0;i<nums_size;++i)
            A^=nums.at(i);
        int sign=A&(-A);
        int a=0,b=0;
        for (int i=1;i<=nums_size;++i)
            if ((i&sign)!=0)
                a^=i;
            else
                b^=i;
        for (int i=0;i<nums_size;++i)
            if ((nums.at(i)&sign)!=0)
                a^=nums.at(i);
            else
                b^=nums.at(i);
        for (int i:nums)
            if (i==a)
                return {a,b};
        return {b,a};
    }
};

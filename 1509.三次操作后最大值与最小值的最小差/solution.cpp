/*
* 要想改变最大值与最小值的差，那我三次移动必然是操作最大值或者是最小值，即排序后的两端
* 不用管它变成什么值，只用知道他变成了不是最大值也不是最小值，是一个中间的值即可
* 那么操作就只有4种可能，现在已经按升序排序
* 1. 最小的3个 最大的0个
  2. 最小的2个 最大的1个
  3. 最小的1个 最大的2个
  4. 最小的0个 最大的3个
  即可以模拟成 a b c d e f g h即
  1. h-d
  2. g-c
  3. f-b
  4. e-a
* 且若size<=4个时，可以直接将另外3个变成和另外一个一样的数字做到所有数字一样即答案为0
*/
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int size=nums.size();
        if (size<=4)
            return 0;
        sort(nums.begin(),nums.end());
        int a=nums.at(0);
        int b=nums.at(1);
        int c=nums.at(2);
        int d=nums.at(3);
        int e=nums.at(size-4);
        int f=nums.at(size-3);
        int g=nums.at(size-2);
        int h=nums.at(size-1);
        int ans=INT_MAX;
        ans=min(ans,h-d);
        ans=min(ans,g-c);
        ans=min(ans,f-b);
        ans=min(ans,e-a);
        return ans;
    }
};

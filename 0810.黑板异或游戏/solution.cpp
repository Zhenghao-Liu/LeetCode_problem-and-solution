/*
 * 轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果等于 0，这个玩家胜利
 * 因此如果一开始异或结果就是0，那么alice就已经赢了
 * step1：先计算数组异或结果，如果是0，alice已经赢了
 * 那如果不是0，无法判断，则需要判断第二步bob必输的情况，才能得出alice必赢
 * 设数组异或和是sumAll，alice擦除一个数后异或和变成sumBob
 * alice为了不输，sumBob一定是不等于0的，sumBob!=0
 * bob要想必输，则代表需要擦除任意一个数后，剩余的异或为0
   则sumBob^nums[i]==0
   拓展即是sumBob^nums[0]==sumBob^nums[1]==···sumBob^nums[n-1]==0
   即所有nums[i]都满足
 * 将这些等式进行异或
   sumBob^nums[0]^sumBob^nums[1]^···sumBob^nums[n-1]==0
   即 (sumBob^sumBob^···sumBob)^(nums[0]^nums[1]^···nums[n-1])==0
   即 (sumBob^sumBob^···sumBob)^sumBob==0
   即 第二步轮到Bob时候共有szBob个数字，总共szBob+1个sumBob异或合为0
   即 szBob+1是个偶数，szBob是个奇数
   即 轮到bob时候如果只有奇数个数字，即在alice第一步时有偶数个数字的话也是必赢
 * step2：alice时nums.size是个偶数，alice必胜  
 */
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=0;
        for (int i:nums) {
            n^=i;
        }
        int sz=nums.size();
        return n==0 || (sz%2)==0;
    }
};
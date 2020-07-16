/*
* 因为是出现2个相同的元素+出现一次的元素，即nums.size()一定是奇数
* 又因为需要logn复杂度，必然是二分
* 可以把nums分为三部分：A、B都是一堆数字，mid是指对应当前mid的一个数字
  A部分 [mid] B部分
* 那么只需要right-mid即可以求出B部分的元素个数，即可以求出B部分是奇数还是偶数
  注意出现一次的元素必然是在奇数的一块区域
* 倘若nums[mid]==nums[mid+1]
  1. 若B部分为偶数，则B部分+mid的个数是奇数，则ans必然在B当中，且当前排除了mid，则left=mid+2
  2. 若B部分为奇数，则B部分+mid的个数是偶数，则ans在A当中，则right=mid-1
* 倘若nums[mid]==nums[mid-1]
  1. 若B部分为偶数，则B部分+mid+（mid+1）的个数还是偶数，即A-1是奇数，则ans在A除去[mid-1]的部分中，即right=mid-2
  2. 若B部分为奇数，则ans在B中，即left=mid+1
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            bool judge_even=(right-mid)%2==0;
            if (nums.at(mid)==nums.at(mid+1))
            {
                if (judge_even)
                    left=mid+2;
                else
                    right=mid-1;
            }
            else if (nums.at(mid)==nums.at(mid-1))
            {
                if (judge_even)
                    right=mid-2;
                else
                    left=mid+1;
            }
            else
                return nums.at(mid);
        }
        return nums.at(left);
    }
};

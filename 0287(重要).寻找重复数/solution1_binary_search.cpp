/*
* [抽屉原理](https://baike.baidu.com/item/抽屉原理/233776)
* 要把这十个苹果放到九个抽屉里，无论怎样放，我们会发现至少会有一个抽屉里面放不少于两个苹果
* 题目说了n+1个数，每个数都在1~n之间
* eg:假设有8个数，即n=7，每个数在1~7之间
* 中间数为mid=4，取值可能[1,2,3,4,5,6,7]
* 若小于等于4的个数count>mid=4，则表明重复的区域是在[1,2,3,4]之间即right=mid
* 若小于等于4的个数count<=mid=4，则表明重复区域在[5,6,7]之间即left=mid+1
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nums_size=nums.size();
        int left=1,right=nums_size-1;
        int mid,count;
        while (left<right)
        {
            mid=left+(right-left)/2;
            count=0;
            for (int &i:nums)
                if (i<=mid)
                    ++count;
            if (count>mid)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};

/*
* 把nums.at(i)看成是链表的next
* 这样就构成了一个有环链表
* 采用[142.环形链表II]方法来做就可以找到重复元素
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums.at(0);
        int fast=nums.at(nums.at(0));
        while (slow!=fast)
        {
            slow=nums.at(slow);
            fast=nums.at(nums.at(fast));
        }
        int start=0;
        while (start!=slow)
        {
            start=nums.at(start);
            slow=nums.at(slow);
        }
        return start;
    }
};

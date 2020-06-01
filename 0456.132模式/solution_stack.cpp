/**
* i<j<k 且[i]<[k]<[j]
* 那么我们可以以j作为处理对象
* 目的就是在j左边找一个i满足比[i]<[j]
  在j右边找一个k满足[j]>[k]
* 既然[i]最小不妨就直接通过从左往右遍历方式
  dp思想找min_i即对于[j]来说左边最小的值
  即转移方程min_i[j]=min(min_i[j-1],nums[j])
* 对于[k]我们用从右往左的单调递减栈
* 因为我们要的是[i]<[k]<[j]，现在[i]即是min_i[j]
  那对于栈中小于等于min_i[j]的元素就没有必要了，可以出栈
* 那是否对于j1出栈了一些元素，对于j2=j1-1影响j2的配对呢
  因为是单调递减栈，且nums[j2=j1-1]>=nums[j1]，又是从左往右找的k
  [j2]要出栈的元素必然是包含了[j1]要包含的元素的
* 最后push(nums[j])是否会影响单调栈
  因为经过出栈后栈内元素全是大于min_i[j]的，且若栈顶小于[j]说明栈顶可以作为[k]那就返回true
  不然的话栈顶必然大于等于[j]，所以加入一个nums[j]不会改变单调递减栈
* 是否考虑到对于j没有[i]符合的情况，这种情况表明在0~j中[j]是最小值
  这种情况下我们考虑j+1分两种可能[j+1]>[j]或[j+1]<[j]，且既然判断到j说明j+1~nums_size-1都是没有132序列的
  1. [j+1]>[j]即[j+1]无法充当[k]
  2. [j+1]<[j]即此时会空栈因为min_i[j]=nums[j]而小于nums[j]的都会出栈
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<=2)
            return false;
        vector<int> min_i(nums_size);
        min_i.at(0)=nums.at(0);
        for (int j=1;j<nums_size;++j)
            min_i.at(j)=min(min_i.at(j-1),nums.at(j));
        stack<int> helper;
        for (int j=nums_size-1;j>=0;--j)
        {
            while (!helper.empty() && helper.top()<=min_i.at(j))
                helper.pop();
            if (!helper.empty() && helper.top()<nums.at(j))
                return true;
            helper.push(nums.at(j));
        }
        return false;
    }
};

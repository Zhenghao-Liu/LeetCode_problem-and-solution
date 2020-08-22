* [个人题解](https://leetcode-cn.com/problems/non-decreasing-array/solution/tui-dao-gui-lu-by-lzh_yves-2/)

给你一个长度为 ```n``` 的整数数组，请你判断在 **最多** 改变 ```1``` 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 ```i (0 <= i <= n-2)```，总满足 ```nums[i] <= nums[i + 1]```。

 

**示例 1:**
```
输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
```
**示例 2:**
```
输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
```

**说明：**

* ```1 <= n <= 10 ^ 4```
* ```- 10 ^ 5 <= nums[i] <= 10 ^ 5```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-decreasing-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

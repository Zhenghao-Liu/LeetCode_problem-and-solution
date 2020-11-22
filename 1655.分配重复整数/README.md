* [推荐题解](https://leetcode-cn.com/problems/distribute-repeating-integers/solution/zi-ji-mei-ju-jing-dian-tao-lu-zhuang-ya-dp-by-arse/)

给你一个长度为 ```n``` 的整数数组 ```nums``` ，这个数组中至多有 ```50``` 个不同的值。同时你有 ```m``` 个顾客的订单 ```quantity``` ，其中，整数 ```quantity[i]``` 是第 ```i``` 位顾客订单的数目。请你判断是否能将 ```nums``` 中的整数分配给这些顾客，且满足：

* 第 ```i``` 位顾客 **恰好** 有 ```quantity[i]``` 个整数。
* 第 ```i``` 位顾客拿到的整数都是 **相同的** 。
* 每位顾客都满足上述两个要求。

如果你可以分配 ```nums``` 中的整数满足上面的要求，那么请返回 ```true``` ，否则返回 ```false``` 。

 

**示例 1：**
```
输入：nums = [1,2,3,4], quantity = [2]
输出：false
解释：第 0 位顾客没办法得到两个相同的整数。
```
**示例 2：**
```
输入：nums = [1,2,3,3], quantity = [2]
输出：true
解释：第 0 位顾客得到 [3,3] 。整数 [1,2] 都没有被使用。
```
**示例 3：**
```
输入：nums = [1,1,2,2], quantity = [2,2]
输出：true
解释：第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [2,2] 。
```
**示例 4：**
```
输入：nums = [1,1,2,3], quantity = [2,2]
输出：false
解释：尽管第 0 位顾客可以得到 [1,1] ，第 1 位顾客没法得到 2 个一样的整数。
```
**示例 5：**
```
输入：nums = [1,1,1,1,1], quantity = [2,3]
输出：true
解释：第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [1,1,1] 。
```

**提示：**

* ```n == nums.length```
* ```1 <= n <= 10^5```
* ```1 <= nums[i] <= 1000```
* ```m == quantity.length```
* ```1 <= m <= 10```
* ```1 <= quantity[i] <= 10^5```
* ```nums``` 中至多有 50 个不同的数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-repeating-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

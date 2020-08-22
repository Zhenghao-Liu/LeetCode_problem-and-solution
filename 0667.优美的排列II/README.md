* [个人题解](https://leetcode-cn.com/problems/beautiful-arrangement-ii/solution/tui-dao-gui-lu-by-lzh_yves/)
* [推荐题解](https://leetcode-cn.com/problems/beautiful-arrangement-ii/solution/fan-jiu-wan-shi-liao-he-he-by-ri-mu-tu-yuan-12/)

给定两个整数 ```n``` 和 ```k```，你需要实现一个数组，这个数组包含从 ```1``` 到 ```n``` 的``` n``` 个不同整数，同时满足以下条件：

① 如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数；.

② 如果存在多种答案，你只需实现并返回其中任意一种.

**示例 1:**
```
输入: n = 3, k = 1
输出: [1, 2, 3]
解释: [1, 2, 3] 包含 3 个范围在 1-3 的不同整数， 并且 [1, 1] 中有且仅有 1 个不同整数 : 1
```

**示例 2:**
```
输入: n = 3, k = 2
输出: [1, 3, 2]
解释: [1, 3, 2] 包含 3 个范围在 1-3 的不同整数， 并且 [2, 1] 中有且仅有 2 个不同整数: 1 和 2
```

**提示:**

1. ```n``` 和 ```k``` 满足条件 1 <= k < n <= 10^4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

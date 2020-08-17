* [推荐题解](https://leetcode-cn.com/problems/2-keys-keyboard/solution/cong-di-gui-dao-su-shu-fen-jie-by-fuxuemingzhu/)
* [推荐题解](https://leetcode-cn.com/problems/2-keys-keyboard/solution/dong-tai-gui-hua-xiang-xi-fen-xi-jie-shi-wei-shi-y/)

最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：

1. ```Copy All``` (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
2. ```Paste``` (粘贴) : 你可以粘贴你**上一次**复制的字符。
给定一个数字 ```n``` 。你需要使用最少的操作次数，在记事本中打印出**恰好** ```n``` 个 'A'。输出能够打印出 ```n``` 个 'A' 的最少操作次数。

**示例 1:**
```
输入: 3
输出: 3
解释:
最初, 我们只有一个字符 'A'。
第 1 步, 我们使用 Copy All 操作。
第 2 步, 我们使用 Paste 操作来获得 'AA'。
第 3 步, 我们使用 Paste 操作来获得 'AAA'。
```
**说明:**

1. ```n``` 的取值范围是 [1, 1000] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

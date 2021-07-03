给你两个字符串 ```s``` 和 ```part``` ，请你对 ```s``` 反复执行以下操作直到 **所有** 子字符串 ```part``` 都被删除：

* 找到 ```s``` 中 **最左边** 的子字符串 ```part``` ，并将它从 ```s``` 中删除。

请你返回从 ```s``` 中删除所有 ```part``` 子字符串以后得到的剩余字符串。

一个 **子字符串** 是一个字符串中连续的字符序列。

 

**示例 1：**
```
输入：s = "daabcbaabcbc", part = "abc"
输出："dab"
解释：以下操作按顺序执行：
- s = "daabcbaabcbc" ，删除下标从 2 开始的 "abc" ，得到 s = "dabaabcbc" 。
- s = "dabaabcbc" ，删除下标从 4 开始的 "abc" ，得到 s = "dababc" 。
- s = "dababc" ，删除下标从 3 开始的 "abc" ，得到 s = "dab" 。
此时 s 中不再含有子字符串 "abc" 。
```
**示例 2：**
```
输入：s = "axxxxyyyyb", part = "xy"
输出："ab"
解释：以下操作按顺序执行：
- s = "axxxxyyyyb" ，删除下标从 4 开始的 "xy" ，得到 s = "axxxyyyb" 。
- s = "axxxyyyb" ，删除下标从 3 开始的 "xy" ，得到 s = "axxyyb" 。
- s = "axxyyb" ，删除下标从 2 开始的 "xy" ，得到 s = "axyb" 。
- s = "axyb" ，删除下标从 1 开始的 "xy" ，得到 s = "ab" 。
此时 s 中不再含有子字符串 "xy" 。
```

**提示：**

* ```1 <= s.length <= 1000```
* ```1 <= part.length <= 1000```
* ```s​​​​​​ 和 part``` 只包小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-occurrences-of-a-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
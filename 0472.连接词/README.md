* [推荐题解](https://leetcode-cn.com/problems/concatenated-words/solution/cqian-zhui-shu-bu-dong-jiu-lai-wen-by-xiaoneng/)

给定一个**不含重复**单词的列表，编写一个程序，返回给定单词列表中所有的连接词。

连接词的定义为：一个字符串完全是由至少两个给定数组中的单词组成的。

**示例:**
```
输入: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

输出: ["catsdogcats","dogcatsdog","ratcatdogcat"]

解释: "catsdogcats"由"cats", "dog" 和 "cats"组成; 
     "dogcatsdog"由"dog", "cats"和"dog"组成; 
     "ratcatdogcat"由"rat", "cat", "dog"和"cat"组成。
```
**说明:**

1. 给定数组的元素总数不超过 ```10000```。
2. 给定数组中元素的长度总和不超过 ```600000```。
3. 所有输入字符串只包含小写字母。
4. 不需要考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/concatenated-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

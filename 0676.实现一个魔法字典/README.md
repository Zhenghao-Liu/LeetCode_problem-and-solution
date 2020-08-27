* [推荐题解](https://blog.csdn.net/qq_41855420/article/details/89421181)

实现一个带有```buildDict```, 以及 ```search```方法的魔法字典。

对于```buildDict```方法，你将被给定一串不重复的单词来构建一个字典。

对于```search```方法，你将被给定一个单词，并且判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。

**示例 1:**
```
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
```
**注意:**

1. 你可以假设所有输入都是小写字母 ```a-z```。
2. 为了便于竞赛，测试所用的数据量很小。你可以在竞赛结束后，考虑更高效的算法。
3. 请记住**重置**MagicDictionary类中声明的类变量，因为静态/类变量会在多个测试用例中保留。 请参阅[这里](http://leetcode.com/faq/#different-output)了解更多详情。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-magic-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

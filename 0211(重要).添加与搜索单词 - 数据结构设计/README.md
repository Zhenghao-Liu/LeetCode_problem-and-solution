* [推荐个人题解](https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/solution/chang-gui-dong-tai-gui-hua-qian-zhui-shu-by-lzh_yv/)

设计一个支持以下两种操作的数据结构：
```
void addWord(word)
bool search(word)
```
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 ```a-z ```。 ```.``` 可以表示任何一个字母。

**示例:**
```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```
**说明:**

你可以假设所有单词都是由小写字母 ```a-z``` 组成的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-and-search-word-data-structure-design
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

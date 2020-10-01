* [官方题解](https://leetcode-cn.com/problems/prefix-and-suffix-search/solution/qian-zhui-he-hou-zhui-sou-suo-by-leetcode/)
* [个人题解](https://leetcode-cn.com/problems/prefix-and-suffix-search/solution/zi-dian-shu-by-lzh_yves/)

给定多个 ```words```，```words[i]``` 的权重为 ```i``` 。

设计一个类 ```WordFilter``` 实现函数```WordFilter.f(String prefix, String suffix)```。这个函数将返回具有前缀 ```prefix``` 和后缀```suffix``` 的词的最大权重。如果没有这样的词，返回 -1。

**例子:**
```
输入:
WordFilter(["apple"])
WordFilter.f("a", "e") // 返回 0
WordFilter.f("b", "") // 返回 -1
```
**注意:**

1. ```words```的长度在```[1, 15000]```之间。
2. 对于每个测试用例，最多会有```words.length```次对```WordFilter.f```的调用。
3. ```words[i]```的长度在```[1, 10]```之间。
4. ```prefix, suffix```的长度在```[0, 10]```之前。
5. ```words[i]```和```prefix, suffix```只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prefix-and-suffix-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

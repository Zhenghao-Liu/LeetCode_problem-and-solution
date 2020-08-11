* [官方题解](https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/solution/zui-xiao-qu-jian-by-leetcode-solution/)

你有 ```k``` 个升序排列的整数列表。找到一个**最小**区间，使得 ```k``` 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 ```b-a < d-c``` 或者在 ```b-a == d-c``` 时 ```a < c```，则区间 [a,b] 比 [c,d] 小。

 

**示例：**
```
输入：[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出：[20,24]
解释： 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
```

**提示：**

* 给定的列表可能包含重复元素，所以在这里升序表示 >= 。
* 1 <= ```k``` <= 3500
* -10^5 <= ```元素的值```  <= 10^5
* **对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。**

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

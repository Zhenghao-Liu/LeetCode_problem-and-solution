* [推荐题解](https://leetcode-cn.com/problems/out-of-boundary-paths/solution/zhuang-tai-ji-du-shi-zhuang-tai-ji-by-christmas_wa/)

给定一个 **m × n** 的网格和一个球。球的起始坐标为 **(i,j)** ，你可以将球移到**相邻**的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。但是，你**最多**可以移动 **N** 次。找出可以将球移出边界的路径数量。答案可能非常大，返回 结果 mod 10^9 + 7 的值。

 

**示例 1：**
```
输入: m = 2, n = 2, N = 2, i = 0, j = 0
输出: 6
解释:
```
![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0576.出界的路径树/out_of_boundary_paths_1.png)

**示例 2：**
```
输入: m = 1, n = 3, N = 3, i = 0, j = 1
输出: 12
解释:
```
![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0576.出界的路径树/out_of_boundary_paths_2.png)

**说明:**

1. 球一旦出界，就不能再被移动回网格内。
2. 网格的长度和高度在 [1,50] 的范围内。
3. N 在 [0,50] 的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/out-of-boundary-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

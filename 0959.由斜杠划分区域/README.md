* [官方题解](https://leetcode-cn.com/problems/regions-cut-by-slashes/solution/you-xie-gang-hua-fen-qu-yu-by-leetcode-67xb/)

在由 1 x 1 方格组成的 N x N 网格 ```grid``` 中，每个 1 x 1 方块由 ```/```、```\``` 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 ```\``` 用 "```\\```" 表示。）。

返回区域的数目。

 

**示例 1：**
```
输入：
[
  " /",
  "/ "
]
输出：2
解释：2x2 网格如下：
```
![img](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0959.由斜杠划分区域/959_1.png)
**示例 2：**
```
输入：
[
  " /",
  "  "
]
输出：1
解释：2x2 网格如下：
```
![img](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0959.由斜杠划分区域/959_2.png)
**示例 3：**
```
输入：
[
  "\\/",
  "/\\"
]
输出：4
解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：
```
![img](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0959.由斜杠划分区域/959_3.png)
**示例 4：**
```
输入：
[
  "/\\",
  "\\/"
]
输出：5
解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：
```
![img](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0959.由斜杠划分区域/959_4.png)
**示例 5：**
```
输入：
[
  "//",
  "/ "
]
输出：3
解释：2x2 网格如下：
```
![img](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0959.由斜杠划分区域/959_5.png) 

**提示：**

* ```1 <= grid.length == grid[0].length <= 30```
* ```grid[i][j]``` 是 ```'/'、'\'、或 ' '```。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

给你一个二进制矩阵 ```matrix``` ，它的大小为 ```m x n``` ，你可以将 ```matrix``` 中的 **列** 按任意顺序重新排列。

请你返回最优方案下将 ```matrix``` 重新排列后，全是 1``` 的子矩阵面积。

 

**示例 1：**

![img1](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/1727.重新排列后的最大子矩阵/1727_1.png)
```
输入：matrix = [[0,0,1],[1,1,1],[1,0,1]]
输出：4
解释：你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
```
**示例 2：**

![img2](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/1727.重新排列后的最大子矩阵/1727_2.png)
```
输入：matrix = [[1,0,1,0,1]]
输出：3
解释：你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
```
**示例 3：**
```
输入：matrix = [[1,1,0],[1,0,1]]
输出：2
解释：由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。
```
**示例 4：**
```
输入：matrix = [[0,0],[0,0]]
输出：0
解释：由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。
```

**提示：**

* ```m == matrix.length```
* ```n == matrix[i].length```
* ```1 <= m * n <= 10^5```
* ```matrix[i][j]``` 要么是 ```0``` ，要么是 ```1``` 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

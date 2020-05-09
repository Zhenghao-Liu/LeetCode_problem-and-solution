* [推荐题解](https://leetcode-cn.com/problems/trapping-rain-water-ii/solution/you-xian-dui-lie-de-si-lu-jie-jue-jie-yu-shui-ii-b/)

给你一个 ```m x n``` 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。

 

**示例：**
```
给出如下 3x6 的高度图:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

返回 4 。
```
![image1](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0407.接雨水II/rainwater_empty.png)

如上图所示，这是下雨前的高度图```[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]``` 的状态。

![image1](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0407.接雨水II/rainwater_fill.png)

下雨后，雨水将会被存储在这些方块中。总的接雨水量是4。

 

**提示：**

* ```1 <= m, n <= 110```
* ```0 <= heightMap[i][j] <= 20000```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

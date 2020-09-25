* [个人题解](https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points/solution/zhuang-ya-dpyi-bu-bu-fen-xi-by-lzh_yves/)
* [推荐题解](https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points/solution/java-zhuang-tai-ya-suo-dp-by-aerysn/)
* [推荐题解](https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points/solution/zhuang-tai-ya-suo-dpmei-ju-zi-ji-you-hua-by-lucife/)
* [B站坑神讲解](https://www.bilibili.com/video/BV1tt4y1q7ES/?p=5)

给你两组点，其中第一组中有 ```size1``` 个点，第二组中有 ```size2``` 个点，且 ```size1 >= size2``` 。

任意两点间的连接成本 ```cost``` 由大小为 ```size1 x size2``` 矩阵给出，其中 ```cost[i][j]``` 是第一组中的点 ```i``` 和第二组中的点 ```j``` 的连接成本。**如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的**。换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。

返回连通两组点所需的最小成本。

 

**示例 1：**

![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1595.连通两组点的最小成本/ex1.jpg)
```
输入：cost = [[15, 96], [36, 2]]
输出：17
解释：连通两组点的最佳方法是：
1--A
2--B
总成本为 17 。
```
**示例 2：**

![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1595.连通两组点的最小成本/ex2.jpg)
```
输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
输出：4
解释：连通两组点的最佳方法是：
1--A
2--B
2--C
3--A
最小成本为 4 。
请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。
```
**示例 3：**
```
输入：cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
输出：10
```

**提示：**

* ```size1 == cost.length```
* ```size2 == cost[i].length```
* ```1 <= size1, size2 <= 12```
* ```size1 >= size2```
* ```0 <= cost[i][j] <= 100```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

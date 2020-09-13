* [最小生成树B站讲解](https://www.bilibili.com/video/BV1Eb41177d1/)
* [推荐题解](https://leetcode-cn.com/problems/min-cost-to-connect-all-points/solution/zui-xiao-sheng-cheng-shu-primsuan-fa-by-kobe24o/)
* [个人mst笔记](https://zhenghao-liu.blog.luogu.org/zui-xiao-sheng-cheng-shu-mst)

给你一个```points``` 数组，表示 2D 平面上的一些点，其中 ```points[i] = [xi, yi]``` 。

连接点 ```[xi, yi]``` 和点 ```[xj, yj]``` 的费用为它们之间的 **曼哈顿距离** ：```|xi - xj| + |yi - yj|``` ，其中 ```|val|``` 表示 ```val``` 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 **有且仅有** 一条简单路径时，才认为所有点都已连接。

 

**示例 1：**

![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1584.连接所有点的最小费用/d.png)
```
输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：
```
![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1584.连接所有点的最小费用/c.png)
```
我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
```
**示例 2：**
```
输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
```
**示例 3：**
```
输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
```
**示例 4：**
```
输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
```
**示例 5：**
```
输入：points = [[0,0]]
输出：0
```

**提示：**

* ```1 <= points.length <= 1000```
* ```-10^6 <= xi, yi <= 10^6```
* 所有点 ```(xi, yi)``` 两两不同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

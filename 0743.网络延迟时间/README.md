* [推荐题解](https://leetcode-cn.com/problems/network-delay-time/solution/dan-yuan-zui-duan-lu-po-su-de-dijkstra-dui-you-hua/)

有 ```N``` 个网络节点，标记为 ```1``` 到 ```N```。

给定一个列表 ```times```，表示信号经过**有向**边的传递时间。 ```times[i] = (u, v, w)```，其中 ```u``` 是源节点，```v``` 是目标节点， ```w``` 是一个信号从源节点传递到目标节点的时间。

现在，我们从某个节点 ```K``` 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 ```-1```。

 

**示例：**

![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0743.网络延迟时间/743_1.png)
```
输入：times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
输出：2
```

**注意:**

1. ```N``` 的范围在 ```[1, 100]``` 之间。
2. ```K``` 的范围在 ```[1, N]``` 之间。
3. ```times``` 的长度在 ```[1, 6000]``` 之间。
4. 所有的边 ```times[i] = (u, v, w)``` 都有 ```1 <= u, v <= N 且 0 <= w <= 100```。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/network-delay-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。```

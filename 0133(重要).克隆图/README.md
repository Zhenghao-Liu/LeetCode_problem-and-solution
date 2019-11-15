* [推荐题解](https://leetcode-cn.com/problems/clone-graph/solution/dfs-he-bfs-by-powcai/)

给定**无向连通图**中一个节点的引用，返回该图的**深拷贝**（克隆）。图中的每个节点都包含它的值 ```val（Int）``` 和其邻居的列表```（list[Node]）```。

**示例：**

![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0133(重要).克隆图/113_sample.png)  
```
输入：
{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

解释：
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。  
```

**提示：**

1. 节点数介于 1 到 100 之间。
2. 无向图是一个**简单图**，这意味着图中没有重复的边，也没有自环。
3. 由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
4. 必须将给定**节点的拷贝**作为对克隆图的引用返回。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

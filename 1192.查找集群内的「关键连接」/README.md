* [推荐题解](https://leetcode-cn.com/problems/critical-connections-in-a-network/solution/1192-cha-zhao-ji-qun-nei-de-guan-jian-lian-jie-jav/)

力扣数据中心有 ```n``` 台服务器，分别按从 ```0``` 到 ```n-1``` 的方式进行了编号。

它们之间以「服务器到服务器」点对点的形式相互连接组成了一个内部集群，其中连接 ```connections``` 是无向的。

从形式上讲，```connections[i] = [a, b]``` 表示服务器 ```a``` 和 ```b``` 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。

「关键连接」是在该集群中的重要连接，也就是说，假如我们将它移除，便会导致某些服务器无法访问其他服务器。

请你以任意顺序返回该集群内的所有 「关键连接」。

 

**示例 1：**

![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1192.%20%E6%9F%A5%E6%89%BE%E9%9B%86%E7%BE%A4%E5%86%85%E7%9A%84%E3%80%8C%E5%85%B3%E9%94%AE%E8%BF%9E%E6%8E%A5%E3%80%8D/critical-connections-in-a-network.png)

```
输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
输出：[[1,3]]
解释：[[3,1]] 也是正确的。
```

**提示：**

* ```1 <= n <= 10^5```
* ```n-1 <= connections.length <= 10^5```
* ```connections[i][0] != connections[i][1]```
* 不存在重复的连接

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/critical-connections-in-a-network
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

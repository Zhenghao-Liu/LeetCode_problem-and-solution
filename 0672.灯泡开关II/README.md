* [推荐题解](https://leetcode-cn.com/problems/bulb-switcher-ii/solution/ying-zhao-chu-lai-de-gui-lu-shuang-bai-tong-guo-by/)
* [推荐题解](https://leetcode-cn.com/problems/bulb-switcher-ii/solution/wei-shi-yao-qian-san-ge-deng-pao-jiu-ke-yi-que-din/)
* [推荐题解](https://leetcode-cn.com/problems/bulb-switcher-ii/solution/zhi-jie-fen-xi-suo-you-ke-neng-de-qing-kuang-by-rl/)

现有一个房间，墙上挂有 ```n``` 只已经打开的灯泡和 4 个按钮。在进行了 ```m``` 次未知操作后，你需要返回这 ```n``` 只灯泡可能有多少种不同的状态。

假设这 ```n``` 只灯泡被编号为 [1, 2, 3 ..., n]，这 4 个按钮的功能如下：

1. 将所有灯泡的状态反转（即开变为关，关变为开）
2. 将编号为偶数的灯泡的状态反转
3. 将编号为奇数的灯泡的状态反转
4. 将编号为 ```3k+1``` 的灯泡的状态反转（k = 0, 1, 2, ...)

**示例 1:**
```
输入: n = 1, m = 1.
输出: 2
说明: 状态为: [开], [关]
```
**示例 2:**
```
输入: n = 2, m = 1.
输出: 3
说明: 状态为: [开, 关], [关, 开], [关, 关]
```
**示例 3:**
```
输入: n = 3, m = 1.
输出: 4
说明: 状态为: [关, 开, 关], [开, 关, 开], [关, 关, 关], [关, 开, 开].
```
**注意**：```n``` 和 ```m``` 都属于 [0, 1000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

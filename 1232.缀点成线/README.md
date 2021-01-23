在一个 XY 坐标系中有一些点，我们用数组 ```coordinates``` 来分别记录它们的坐标，其中 ```coordinates[i] = [x, y]``` 表示横坐标为 ```x```、纵坐标为 ```y``` 的点。

请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 ```true```，否则请返回 ```false```。

 

**示例 1：**

![img1](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/1232.缀点成线/1232_1.jpg)
```
输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
输出：true
```
**示例 2：**

![img2](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/1232.缀点成线/1232_2.jpg)
```
输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
输出：false
```

**提示：**

* ```2 <= coordinates.length <= 1000```
* ```coordinates[i].length == 2```
* ```-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4```
* ```coordinates``` 中不含重复的点

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-it-is-a-straight-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

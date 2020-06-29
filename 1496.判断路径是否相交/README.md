给你一个字符串 ```path```，其中 ```path[i]``` 的值可以是 ```'N'、'S'、'E'``` 或者 ```'W'```，分别表示向北、向南、向东、向西移动一个单位。

机器人从二维平面上的原点 ```(0, 0)``` 处开始出发，按 ```path``` 所指示的路径行走。

如果路径在任何位置上出现相交的情况，也就是走到之前已经走过的位置，请返回 ```True``` ；否则，返回 ```False``` 。

 

**示例 1：**

![image1](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1496.%E5%88%A4%E6%96%AD%E8%B7%AF%E5%BE%84%E6%98%AF%E5%90%A6%E7%9B%B8%E4%BA%A4/screen-shot-2020-06-10-at-123929-pm.png)
```
输入：path = "NES"
输出：false 
解释：该路径没有在任何位置相交。
```
**示例 2：**

![image2](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/1496.%E5%88%A4%E6%96%AD%E8%B7%AF%E5%BE%84%E6%98%AF%E5%90%A6%E7%9B%B8%E4%BA%A4/screen-shot-2020-06-10-at-123843-pm.png)
```
输入：path = "NESWW"
输出：true
解释：该路径经过原点两次。
```

**提示：**

* ```1 <= path.length <= 10^4```
* ```path``` 仅由 ```{'N', 'S', 'E', 'W}``` 中的字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-crossing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

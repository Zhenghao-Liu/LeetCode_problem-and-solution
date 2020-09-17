Range 模块是跟踪数字范围的模块。你的任务是以一种有效的方式设计和实现以下接口。

* ```addRange(int left, int right)``` 添加半开区间 ```[left, right)```，跟踪该区间中的每个实数。添加与当前跟踪的数字部分重叠的区间时，应当添加在区间 ```[left, right)``` 中尚未跟踪的任何数字到该区间中。
* ```queryRange(int left, int right)``` 只有在当前正在跟踪区间 ```[left, right)``` 中的每一个实数时，才返回 ```true```。
* ```removeRange(int left, int right)``` 停止跟踪区间 ```[left, right)``` 中当前正在跟踪的每个实数。
 

**示例：**
```
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true （区间 [10, 14) 中的每个数都正在被跟踪）
queryRange(13, 15): false （未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
queryRange(16, 17): true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
```

**提示：**

* 半开区间 ```[left, right)``` 表示所有满足 ```left <= x < right``` 的实数。
* 对 ```addRange, queryRange, removeRange``` 的所有调用中 ```0 < left < right < 10^9```。
* 在单个测试用例中，对 ```addRange``` 的调用总数不超过 ```1000``` 次。
* 在单个测试用例中，对  ```queryRange``` 的调用总数不超过 ```5000``` 次。
* 在单个测试用例中，对 ```removeRange``` 的调用总数不超过 ```1000``` 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-module
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

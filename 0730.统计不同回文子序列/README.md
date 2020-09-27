* [官方题解](https://leetcode-cn.com/problems/count-different-palindromic-subsequences/solution/tong-ji-bu-tong-hui-wen-zi-zi-fu-chuan-by-leetcode/)
* [推荐题解](https://blog.csdn.net/qq_41855420/article/details/89710028?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522160121927519725271720158%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=160121927519725271720158&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_v1~rank_blog_v1-2-89710028.pc_v1_rank_blog_v1&utm_term=LeetCode+%E7%BB%9F%E8%AE%A1%E4%B8%8D%E5%90%8C%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97&spm=1018.2118.3001.4187)

给定一个字符串 S，找出 S 中不同的非空回文子序列个数，并**返回该数字与 10^9 + 7 的模**。

通过从 S 中删除 0 个或多个字符来获得子序列。

如果一个字符序列与它反转后的字符序列一致，那么它是回文字符序列。

如果对于某个  ```i，A_i != B_i```，那么 ```A_1, A_2, ... 和 B_1, B_2, ...``` 这两个字符序列是不同的。

 

**示例 1：**
```
输入：
S = 'bccb'
输出：6
解释：
6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
注意：'bcb' 虽然出现两次但仅计数一次。
```
**示例 2：**
```
输入：
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
输出：104860361
解释：
共有 3104860382 个不同的非空回文子序列，对 10^9 + 7 取模为 104860361。
```

**提示：**

* 字符串 ```S``` 的长度将在```[1, 1000]```范围内。
* 每个字符 ```S[i]``` 将会是集合 ```{'a', 'b', 'c', 'd'}``` 中的某一个。
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-different-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

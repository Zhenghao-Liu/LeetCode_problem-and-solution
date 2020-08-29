/*
* A要么长于B要么短于B
* A_size>=B_size
  1. 要么B是A的子串
  2. 要么B是string(A+A)的子串
  3. 不是子串，-1
* A_size<B_size
  即需要多个A才能构造出B，设多个A为final_A（final_A是最短满足要求情况）
  final_A=AA···AA
  那么B一定会占用最开始的A的后一部分，也会占用最后一个A的前一部分
  即AA···AA中B完全占用了[]范围的大小，即A[A···A]A，两边界的A占用了一部分
  所以整数除法B_size/A_size最小能求得[]内有几个A，
  为了一定能求出final_A有几个A，加上两边界的A
  即upper=B_size/A_size+2
* 其实A_size>=B_size的情况upper也就是2，所以可以一起讨论
*/
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int A_size=A.size();
        int B_size=B.size();
        int cur_A=1;
        string final_A=A;
        int upper=B_size/A_size+2;
        while (cur_A<=upper)
        {
            if (final_A.find(B)!=string::npos)
                return cur_A;
            final_A+=A;
            ++cur_A;
        }
        return -1;
    }
};

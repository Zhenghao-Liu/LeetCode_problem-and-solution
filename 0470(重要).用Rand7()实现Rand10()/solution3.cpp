//按照图的方式来生成![image](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/blob/master/0470(重要).用Rand7()实现Rand10()/rejectionSamplingTable.png)
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row,column,index;
        do
        {
            row=rand7();
            column=rand7();
            index=column+(row-1)*7;
        }while (index>40);
        return 1+index%10;
    }
};

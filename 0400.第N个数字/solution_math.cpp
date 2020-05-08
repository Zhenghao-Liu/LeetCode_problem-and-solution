/*
* 1~9 9个
* 10~99 90*2个
* 100~999 900*3个
* 1000~9999 9000*4个
* 得出在哪个区间再找到是哪个数字，再找索引
*/
class Solution {
public:
    int findNthDigit(int n) {
        if (n<=9)
            return n;
        long long count=9;
        int size=1;
        long long base=9;
        int end=-1;
        int last_count=0;
        while (count<n)
        {
            last_count=count;
            if (end==-1)
                end=9;
            else
                end=end*10+9;
            ++size;
            base*=10;
            count+=size*base;
        }
        //表示在哪个完整的数当中
        int num=end+(n-last_count-1+size)/size;
        //begin_index是num这个数字第一位的索引
        int begin_index=last_count+(num-end-1)*size+1;
        return to_string(num).at(n-begin_index)-'0';
    }
};

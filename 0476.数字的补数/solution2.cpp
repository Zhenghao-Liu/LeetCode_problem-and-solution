//统计num有多少位，然后填满对应的1设为key，将key与num异或，因为1^0=1 1^1=0即任意数与1异或得到任意数的反
class Solution {
public:
    int findComplement(int num) {
        int n=num;
        int key=0;
        while (n!=0)
        {
            n>>=1;
            key<<=1;
            key+=1;
        }
        return key^num;
    }
};

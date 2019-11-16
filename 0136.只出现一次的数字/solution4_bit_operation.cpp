/*
* 采用异或^运算
* 0^0=0
* 0^1=1
* 1^0=1
* 1^1=0
* 由以上基本运算得
* 0^a=a
* a^a=0
* 且异或具有交换律
* eg:[a,a,b,b,c]
* a^a^b^b^c=0^b^b^c=b^b^c=0^c=c
* 从头到尾异或运算即可
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer=0;
        for (int i:nums)
            answer=answer^i;
        return answer;
    }
};

//全局倒置包含了局部倒置，所以只要找到一个全局倒置且它不是局部倒置，就可以返回false，那么就贪心的找i+2~size-1的最小值，判断是否构成全局倒置
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int size=A.size();
        if (size<=2)
            return true;
        int min_v=A.back();
        for (int i=size-3;i>=0;--i)
        {
            if (A.at(i)>min_v)
                return false;
            min_v=min(min_v,A.at(i+1));
        }
        return true;
    }
};

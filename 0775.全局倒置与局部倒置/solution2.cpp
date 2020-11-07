//需要根据题目的数据量进行分析总结
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int size=A.size();
        for (int i=0;i<size;++i)
            if (abs(A.at(i)-i)>1)
                return false;
        return true;
    }
};

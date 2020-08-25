//暴力枚举所有交换情况
class Solution {
public:
    int maximumSwap(int num) {
        int max_num=num;
        string s=to_string(num);
        int s_size=s.size();
        for (int i=0;i<s_size;++i)
            for (int j=i+1;j<s_size;++j)
            {
                swap(s.at(i),s.at(j));
                max_num=max(max_num,stoi(s));
                swap(s.at(i),s.at(j));
            }
        return max_num;
    }
};

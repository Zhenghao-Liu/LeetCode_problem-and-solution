//记录下每一步结果，如果有重复则代表出现了循环，即不可能是快乐数
class Solution {
public:
    bool isHappy(int n) {
        int s,m=n;
        unordered_set<int> set_m;
        do
        {
            s=m;
            set_m.insert(m);
            m=0;
            while(s!=0)
            {
                m=m+pow(s%10,2);
                s=s/10;
            }
        }while (set_m.find(m)==set_m.end() && m!=1);
        return m==1;
    }
};

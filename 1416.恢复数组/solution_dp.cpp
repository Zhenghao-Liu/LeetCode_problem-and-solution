class Solution {
public:
    int base=1e9+7;
    int numberOfArrays(string s, int k) {
        int s_size=s.size();
        vector<int> dp(s_size+1);
        dp.at(0)=1;
        string temp;
        temp.reserve(10);
        for (int i=1;i<=s_size;++i)
            for (int j=i;j>0 && i-j+1<=10;--j)
            {
                temp=s.substr(j-1,i-j+1);
                if (temp.at(0)=='0')
                    continue;
                if (stol(temp)>k)
                    break;
                dp.at(i)+=dp.at(j-1);
                dp.at(i)%=base;
            }
        return dp.at(s_size);
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        string temp;
        for (int i=0;i<12;++i)
            for (int j=0;j<60;++j)
                if (number_of_1(i)+number_of_1(j)==num)
                {
                    temp.clear();
                    temp+=to_string(i)+':';
                    if (j/10==0)
                        temp+='0';
                    temp+=to_string(j);
                    ans.push_back(temp);
                }
        return ans;
    }
    int number_of_1(int n)
    {
        int count=0;
        while (n!=0)
        {
            /**
            * 这一步是将n的最右边的1变为0
            * 倘若是以1结尾，那减一则变成0，与则为0
            * 倘若是以0结尾，即1····1···0B
            * 那减一会一直向前面的1借位，即借位的1对应是0，且后面0都对应1，与也是消除1
            * 所以这里count作用就是记录n二进制下有几个1
            */
            n&=(n-1);
            ++count;
        }
        return count;
    }
};

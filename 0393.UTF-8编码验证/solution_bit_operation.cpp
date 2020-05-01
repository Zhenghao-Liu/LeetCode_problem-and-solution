class Solution {
public:
    bool validUtf8(vector<int>& data) {
        //128D=100 000 00B
        int check_1_base=128;
        //191D=101 111 11B
        int check_0_base=191;
        int count_n=0;
        int key;
        for (int &i:data)
        {
            if (count_n==0)
            {
                key=check_1_base;
                //count_n用来检查是几字节的字符
                //即前面有几个1
                while ( (key&i) == key)
                {
                    ++count_n;
                    key>>=1;
                    if (count_n==5)
                        return false;
                }
                //注意1字节时是以0开头的
                if (count_n==1)
                    return false;
                //n个字节字符则后面跟n-1个10
                if (count_n!=0)
                    --count_n;
            }
            else
            {
                --count_n;
                //检查是否是前缀为10
                if (! ((i&check_1_base)==check_1_base && (i|check_0_base)==check_0_base) )
                    return false;
            }
        }
        return count_n==0;
    }
};

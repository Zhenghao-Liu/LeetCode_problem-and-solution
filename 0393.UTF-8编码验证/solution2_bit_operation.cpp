class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=0;
        for (int &i:data)
            if (n>0)
            {
                //判断开始是否是以10为开头
                if (i>>6!=2)
                    return false;
                --n;
            }
            //1字节即以0为开头
            else if (i>>7==0)
                n=0;
            //2字节
            else if (i>>5==0b110)
                n=1;
            //3字节
            else if (i>>4==0b1110)
                n=2;
            //4字节
            else if (i>>3==0b11110)
                n=3;
            else
                return false;
        return n==0;
    }
};

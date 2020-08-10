//模拟
class Solution {
public:
    char findKthBit(int n, int k) {
        string ans="0";
        string t;
        for (int i=2;i<=n;++i)
        {
            t.clear();
            int length=ans.size();
            for (int j=length-1;j>=0;--j)
                if (ans.at(j)=='1')
                    t+="0";
                else
                    t+="1";
            ans+="1"+t;
            //剪枝
            if ((int)ans.size()>=k)
                break;
        }
        return ans.at(k-1);
    }
};
